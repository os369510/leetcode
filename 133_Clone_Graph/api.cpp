/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* visit[101];
    Node* _cloneGraph(Node* node) {
        if (visit[node->val] != 0)
            return visit[node->val];
        Node *newnode = new Node(node->val);
        visit[node->val] = newnode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node *neighbor = node->neighbors[i], *nb;
            nb = _cloneGraph(neighbor);
            newnode->neighbors.push_back(nb);
        }
        return newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        if (node->neighbors.empty() == true) return new Node(node->val, node->neighbors);
        return _cloneGraph(node);
    }
};
