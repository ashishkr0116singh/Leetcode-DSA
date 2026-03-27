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
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int* result = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;

    while (front < rear) {
        int levelSize = rear - front;
        struct TreeNode* node = NULL;

        for (int i = 0; i < levelSize; i++) {
            node = queue[front++];

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        // The last node processed at this level is the rightmost one
        result[*returnSize] = node->val;
        (*returnSize)++;
    }

    return result;
}
