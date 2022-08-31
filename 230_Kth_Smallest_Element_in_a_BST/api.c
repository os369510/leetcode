/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
enum _from {
    right,
    left,
    num
};
// high 16bits : greater than caller
// low 16 bits : less than caller
int _kthSmallest(struct TreeNode* root, int k, int hmwltu, int *res, enum _from f){
    int sn = 0, gn = 0, ret = 0;
    if (!root) return -1;
    // left
    ret = _kthSmallest(root->left, k, hmwltu, res, right);
    if (ret != -1) {
        sn = ret & 0xffff;
        sn -= hmwltu;
    }
    // right
    ret = _kthSmallest(root->right, k, hmwltu + sn + 1, res, left);
    if (ret != -1)
        gn = ret >> 16;
    if (hmwltu + sn == k - 1)
        *res = root->val;
    if (f == left)
        return (hmwltu - 1) | (gn + sn + 1) << 16;
    else if (f == right)
        return (1 + hmwltu + sn + gn);
    else
        return *res;
}
int kthSmallest(struct TreeNode* root, int k){
    int res = 0;
    return _kthSmallest(root, k, 0, &res, num);
}
