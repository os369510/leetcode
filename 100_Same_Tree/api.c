/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    bool ret = true;
    if (p) {
        if ((!q) ||
            (p->val != q->val) ||
            (p->left && !(q->left)) ||
            (p->right && !(q->right)) ||
            (q->left && !(p->left)) ||
            (q->right && !(p->right)))
            return false;
    }
    if (!p && q)
        return false;
    if (!p && !q)
        return true;
    ret &= isSameTree(p->left, q->left);
    ret &= isSameTree(p->right, q->right);
    return ret;
}
