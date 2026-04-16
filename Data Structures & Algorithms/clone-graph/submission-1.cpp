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
public:
    Node* cloneGraph(Node* node) {
        Node* res;
        dfs(node, res);
        return res;
    }

    void dfs(Node* curNode, Node* res)
    {
        if (!curNode) return;
        if (curNode->val != -1) return;
        if (!res) res = new Node(curNode->val);
        
        for (Node* n : curNode->neighbors)
        {
            res->neighbors.push_back(new Node(n->val));
            dfs(n, res);
            n->val = -1;
        }

        
    }
};
