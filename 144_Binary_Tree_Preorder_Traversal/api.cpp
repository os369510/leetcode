/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> mystack;
        vector<int> ret;
        if (!root) return ret;
        mystack.push(root);
        while (mystack.size() > 0) {
            TreeNode *node = mystack.top();
            mystack.pop();
            ret.push_back(node->val);
            if (node->right) mystack.push(node->right);
            if (node->left) mystack.push(node->left);
        }
        return ret;
    }
};
