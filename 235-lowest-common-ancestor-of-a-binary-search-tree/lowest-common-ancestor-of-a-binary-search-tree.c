/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, 
                                      struct TreeNode* p, 
                                      struct TreeNode* q) {
    while (root != NULL) {
        // If both p and q are smaller, LCA lies in the left subtree
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both p and q are greater, LCA lies in the right subtree
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // Otherwise, root is the split point → LCA
        else {
            return root;
        }
    }
    return NULL; // safety check
}