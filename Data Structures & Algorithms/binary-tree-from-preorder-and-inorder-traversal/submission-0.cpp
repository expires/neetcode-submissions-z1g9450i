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
    int pI = 0;
    int iI = 0;

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int lim)
    {
        if (pI >= preorder.size()) return nullptr;
        if (inorder[iI] == lim)
        {
            iI++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pI++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, lim);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return dfs(preorder, inorder, INT_MAX);
    }
};
