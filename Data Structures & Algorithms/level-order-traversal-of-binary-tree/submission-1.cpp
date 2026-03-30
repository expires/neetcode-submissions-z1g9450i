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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        
        add(ret, root, 0);

        return ret;

    }

    void add(vector<vector<int>>& v, TreeNode* root, int d)
    {
        if (root)
        {
            if (v.size() == d)
            {
                v.push_back({});
            }
            v[d].push_back(root->val);
            add(v, root->left, d+1);
            add(v, root->right, d+1);
        }
    }
};
