/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloc'ed, assume caller calls free().
 */
void preorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;
    result[(*returnSize)++] = root->val;       // Visit root
    preorderHelper(root->left, result, returnSize);  // Traverse left
    preorderHelper(root->right, result, returnSize); // Traverse right
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    // Allocate space for result (max nodes = 100 for LeetCode constraints)
    int* result = (int*)malloc(100 * sizeof(int));

    preorderHelper(root, result, returnSize);

    return result;
}