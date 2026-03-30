/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTreeHelper(int* preorder, int preStart, int preEnd,
                                 int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    // Root is always the first element in preorder
    int rootVal = preorder[preStart];
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
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize,
                                 inorder, inStart, inRootIndex - 1);

    root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd,
                                  inorder, inRootIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) return NULL;
    return buildTreeHelper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
