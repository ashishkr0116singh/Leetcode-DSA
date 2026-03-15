/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorderHelper(struct TreeNode* root, int* arr, int* size) {
    if (root == NULL) return;
    inorderHelper(root->left, arr, size);
    arr[(*size)++] = root->val;
    inorderHelper(root->right, arr, size);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * 1000); // assume max 1000 nodes
    *returnSize = 0;
    inorderHelper(root, result, returnSize);
    return result;
}