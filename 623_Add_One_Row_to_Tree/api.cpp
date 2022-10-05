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
#include <queue>
class Solution {
private:
    queue<TreeNode*> q;
    void bfs(int cur_layer, int val, int depth) {
        int len = q.size();
        bool arrived = (cur_layer + 1 == depth);
        TreeNode *node, *l, *r, *new_node;
        for (int i = 0; i < len; i++) {
            node = q.front();
            q.pop();
            if (arrived) {
                new_node = new TreeNode(val, node->left, NULL);
                node->left = new_node;
                new_node = new TreeNode(val, NULL, node->right);
                node->right = new_node;
            }
            else {
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        if (arrived)
            return;
        bfs(cur_layer + 1, val, depth);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *newnode = new TreeNode(val, root, NULL);
            return newnode;
        }
        q.push(root);
        bfs(1, val, depth);
        return root;
    }
};
