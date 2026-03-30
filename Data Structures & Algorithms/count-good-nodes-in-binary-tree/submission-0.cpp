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
    int goodNodes(TreeNode* root) {
        int c = 0;
        count(c, root, INT_MIN);
        return c;
    }

    void count(int& c, TreeNode* root, int prev)
    {
        if (!root) return;
        if (root->val >= prev)
        {
            c++;
        }
        int maxSoFar = max(prev, root->val);
        count(c, root->left, maxSoFar);
        count(c, root->right, maxSoFar);
    }
};
