/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool _isValidBST(struct TreeNode* root, long *max, long *min){
    long mar = LONG_MIN, mir = LONG_MAX;
    long mal = LONG_MIN, mil = LONG_MAX;
    bool ret = true;
    if (!root)
        return ret;
    ret &= _isValidBST(root->left, &mal, &mil);
    if (!ret || root->val <= mal)
        return false;
    ret &= _isValidBST(root->right, &mar, &mir);
    if (!ret || root->val >= mir)
        return false;
    if (mar < root->val)
        mar = root->val;
    if (mil > root->val)
        mil = root->val;
    *max = mar;
    *min = mil;
    return ret;
}

bool isValidBST(struct TreeNode* root){
    long ma = LONG_MIN, mi = LONG_MAX;
    return _isValidBST(root, &ma, &mi);
}
