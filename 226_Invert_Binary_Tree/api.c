/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void _invertTree(struct TreeNode* root){
    if (!root)
        return;
    struct TreeNode *tmp;
    _invertTree(root->right);
    _invertTree(root->left);
    tmp = root->right;
    root->right = root->left;
    root->left = tmp;    
}
struct TreeNode* invertTree(struct TreeNode* root){
    _invertTree(root);
    return root;
}
