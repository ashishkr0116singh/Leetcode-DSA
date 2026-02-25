/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect if a cycle exists using Floyd’s Tortoise and Hare
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find the entry point of the cycle
            struct ListNode *entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // Cycle entry node
        }
    }

    return NULL; // No cycle
}