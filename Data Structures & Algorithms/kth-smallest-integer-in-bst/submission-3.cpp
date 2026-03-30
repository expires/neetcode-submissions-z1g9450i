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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ret = INT_MIN;

        dfs(root, k, count, ret);

        return ret;

    }

    void dfs(TreeNode* node, int k, int& count, int& ret)
    {
        if (!node || count >= k) return;
        dfs(node->left, k, count, ret);
        count++;

        if (count == k)
        {
            ret = node->val;
            return;
        }
        
        dfs(node->right, k, count, ret);
    }
};
