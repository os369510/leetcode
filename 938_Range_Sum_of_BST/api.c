/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int search(struct TreeNode* root, int low, int high, int sum) {
    if (!root)
        return sum;
    if (root->val >= low && root->val <= high)
        sum += root->val;
    if (root->left) {
        sum = search(root->left, low, high, sum);
    }
    if (root->right) {
        sum = search(root->right, low, high, sum);
    }
    return sum;
}


int rangeSumBST(struct TreeNode* root, int low, int high){
    return search(root, low, high, 0);
}
