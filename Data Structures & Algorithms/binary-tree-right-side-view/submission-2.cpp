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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        dfs(ret, root, 0);
        return ret;
    }

    void dfs(vector<int>& r, TreeNode* root, int d)
    {
        if (!root) return;
        if (d == r.size())
            r.push_back(root->val);

        dfs(r, root->right, d + 1);
        dfs(r, root->left, d + 1);
    }
};
