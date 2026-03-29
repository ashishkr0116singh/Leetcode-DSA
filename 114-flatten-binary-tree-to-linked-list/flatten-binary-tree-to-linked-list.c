/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    if (root == NULL) return;

    // Flatten left and right subtrees
    flatten(root->left);
    flatten(root->right);

    // Store the right subtree
    struct TreeNode* tempRight = root->right;

    // Move the left subtree to the right
    root->right = root->left;
    root->left = NULL;

    // Find the tail of the new right subtree
    struct TreeNode* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }

    // Attach the original right subtree
    curr->right = tempRight;
}
