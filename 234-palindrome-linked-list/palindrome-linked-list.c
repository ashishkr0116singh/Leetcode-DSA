/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // Step 1: Find the middle using slow and fast pointers
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;
    struct ListNode* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Step 3: Compare first half and reversed second half
    struct ListNode* p1 = head;
    struct ListNode* p2 = prev;
    while (p2 != NULL) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}