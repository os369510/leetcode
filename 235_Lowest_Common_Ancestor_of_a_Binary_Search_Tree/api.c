/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
enum dir {
    nodecide = 0,
    right,
    left,
};
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    enum dir pdir, qdir;
    if (p->val == root->val || q->val == root->val)
        return root;
    if (p->val > root->val)
        pdir = right;
    else
        pdir = left;
    if (q->val > root->val)
        qdir = right;
    else
        qdir = left;
    if (pdir != qdir)
        return root;
    if (pdir == right)
        root = root->right;
    else
        root = root->left;
    return lowestCommonAncestor(root, p, q);
}
