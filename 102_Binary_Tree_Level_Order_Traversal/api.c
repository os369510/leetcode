/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int _levelOrder(struct TreeNode *root, int **ret, int **rcs, int level, int *max) {
    if (!root)
        return;
    if (*max < level)
        *max = level;
    ret[level][((*rcs)[level])++] = root->val;
    _levelOrder(root->left, ret, rcs, level + 1, max);
    _levelOrder(root->right, ret, rcs, level + 1, max);
    return;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **ret, max = 0;
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    ret = calloc(2000, sizeof(int*));
    *returnColumnSizes = calloc(2000, sizeof(int));
    for (int i = 0; i < 2000; i++) {
        (*returnColumnSizes)[i] = 0;
        ret[i] = calloc(200, sizeof(int));
    }
    
    _levelOrder(root, ret, returnColumnSizes, 0, &max);
    *returnSize = max + 1;
    return ret;
}
