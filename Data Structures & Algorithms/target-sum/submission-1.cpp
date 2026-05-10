class Solution {
public:
    int offset = 1000;

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> memo(nums.size(), vector<int>(2001, INT_MIN));
        return dfs(memo, nums, 0, target);
    }

    int dfs(vector<vector<int>>& memo, vector<int>& nums, int i, int a)
    {
        if (i == nums.size() && a == 0) return 1;
        if (i >= nums.size()) return 0;
        if (memo[i][a + offset] != INT_MIN) return memo[i][a + offset];

        int res = 0;

        res = dfs(memo, nums, i + 1, a - nums[i]);
        res += dfs(memo, nums, i + 1, a + nums[i]);


        memo[i][a + offset] = res;
        return res;

    }
};
