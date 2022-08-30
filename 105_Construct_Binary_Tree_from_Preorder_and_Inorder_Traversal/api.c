/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int idx = 0;
    struct TreeNode *tmp = NULL;
    if (inorderSize <= 0 || preorderSize <= 0)
        return NULL;
    if (inorderSize == 1) {
        tmp = calloc(1, sizeof(struct TreeNode));
        tmp->val = preorder[0];
        return tmp;
    }
    while (inorder[idx] != preorder[0]) idx++;
    tmp = calloc(1, sizeof(struct TreeNode));
    tmp->val = preorder[0];
    // leff
    tmp->left = buildTree(preorder+1, preorderSize - (1 + (inorderSize - (idx + 1))), inorder, idx);
    // right
    tmp->right = buildTree(preorder+idx+1, preorderSize - (1 + idx), inorder + idx + 1, inorderSize - (idx + 1));
    return tmp;
}
