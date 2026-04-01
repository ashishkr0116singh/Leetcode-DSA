/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

enum State { HAS_CAMERA, COVERED, NEED_CAMERA };

int cameras;

enum State dfs(struct TreeNode* root) {
    if (root == NULL) return COVERED;

    enum State left = dfs(root->left);
    enum State right = dfs(root->right);

    if (left == NEED_CAMERA || right == NEED_CAMERA) {
        cameras++;
        return HAS_CAMERA;
    }

    if (left == HAS_CAMERA || right == HAS_CAMERA) {
        return COVERED;
    }

    return NEED_CAMERA;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == NEED_CAMERA) {
        cameras++;
    }
    return cameras;
}
