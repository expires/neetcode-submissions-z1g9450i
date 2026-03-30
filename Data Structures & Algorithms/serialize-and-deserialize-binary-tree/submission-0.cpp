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

class Codec {
private:
    void dfs(string& s, TreeNode* node)
    {
        if (node)
        {
            s += to_string(node->val);
            s += ',';
            dfs(s, node->left);
            dfs(s, node->right);
        }
        else
        {
            s+= 'N';
            s += ',';
            return;
        }
    }

    TreeNode* deDfs(vector<string>& s, int& i)
    {
        if (s[i] == "N") { i++; return nullptr; }
        TreeNode* root = new TreeNode(stoi(s[i++]));
        root->left = deDfs(s, i);
        root->right = deDfs(s, i);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        dfs(s, root);
        cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string token;
        int i = 0;
        while (getline(ss, token, ',')) tokens.push_back(token);
        return deDfs(tokens, i);

    }
};
