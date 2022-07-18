/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Just compare the tree. */
bool comp(struct TreeNode* root, struct TreeNode* subroot, bool ret) {
    if (!ret)
        return ret;
    if (!root && !subroot)
        return true;
    
    if ((!root && subroot) ||
        (!subroot && root) ||
        (root->val != subroot->val))
        return false;
    
    if ((root->val == subroot->val) &&
        (root->left == subroot->left) &&
        (root->right == subroot->right))
        return true;
    
    ret = comp(root->left, subroot->left, ret);
    ret = comp(root->right, subroot->right, ret);
    
    return ret;
}

/* Visit all nodes and compare them */
bool _isSubtree(struct TreeNode* root, struct TreeNode* subroot, bool ret){
    if (ret)
        return ret;
    ret = comp(root, subroot, true);
    if (root->left)
        ret = _isSubtree(root->left, subroot, ret);
    if (root->right)
        ret = _isSubtree(root->right, subroot, ret);
    return ret;
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    bool ret = false;
    ret = _isSubtree(root, subRoot, false);
    return ret;
}

