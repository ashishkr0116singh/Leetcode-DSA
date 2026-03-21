/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isLeaf(struct TreeNode* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;

    int sum = 0;

    // Check if left child is a leaf
    if (isLeaf(root->left)) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }

    // Recurse on right child (but only add left leaves from its subtree)
    sum += sumOfLeftLeaves(root->right);

    return sum;
}