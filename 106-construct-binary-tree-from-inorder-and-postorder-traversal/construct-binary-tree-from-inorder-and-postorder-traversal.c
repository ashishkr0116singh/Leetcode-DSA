/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTreeHelper(int* inorder, int inStart, int inEnd,
                                 int* postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    // Root is always the last element in postorder
    int rootVal = postorder[postEnd];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;

    // Find root index in inorder
    int inRootIndex = inStart;
    while (inRootIndex <= inEnd && inorder[inRootIndex] != rootVal) {
        inRootIndex++;
    }

    int leftTreeSize = inRootIndex - inStart;

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(inorder, inStart, inRootIndex - 1,
                                 postorder, postStart, postStart + leftTreeSize - 1);

    root->right = buildTreeHelper(inorder, inRootIndex + 1, inEnd,
                                  postorder, postStart + leftTreeSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0 || postorderSize == 0) return NULL;
    return buildTreeHelper(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
