/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _maxDepth(struct TreeNode *root, int level, int *max) {
    if (!root)
        return;
    if (level > *max)
        *max = level;
    _maxDepth(root->left, level + 1, max);
    _maxDepth(root->right, level + 1, max);
    return;
}

int maxDepth(struct TreeNode* root){
    if (!root) return 0;
    int max = 0;
    _maxDepth(root, 1, &max);
    return max;
}
