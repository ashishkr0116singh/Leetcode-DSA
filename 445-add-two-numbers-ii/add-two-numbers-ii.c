#include <stdio.h>
#include <stdlib.h>

// ✅ Do NOT redefine struct ListNode here — LeetCode already provides it.
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s1[1000], s2[1000];  // stacks
    int top1 = -1, top2 = -1;

    // Fill stacks
    while (l1) {
        s1[++top1] = l1->val;
        l1 = l1->next;
    }
    while (l2) {
        s2[++top2] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    // Process stacks
    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;
        if (top1 >= 0) sum += s1[top1--];
        if (top2 >= 0) sum += s2[top2--];

        carry = sum / 10;
        struct ListNode* newNode = createNode(sum % 10);

        // Insert at head
        newNode->next = result;
        result = newNode;
    }

    return result;
}