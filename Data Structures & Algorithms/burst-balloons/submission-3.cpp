class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> ne(n + 2, 1);
        for (int i = 0; i < n; i++) {
            ne[i + 1] = nums[i];
        }

        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        return dfs(memo, ne, 1, ne.size() - 2);
    }

    int dfs(vector<vector<int>>& memo, vector<int>& nums, int l, int r)
    {
        if (l > r) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        memo[l][r] = 0;
        for (int i = l; i <= r; i++)
        {
            int coins = nums[l - 1] * nums[i] * nums[r+1];
            coins += dfs(memo, nums, l, i - 1) + dfs(memo, nums, i + 1, r);
            memo[l][r] = max(memo[l][r], coins);
        }
        return memo[l][r];

    }
};
