class Solution {
public:
    vector<int> memo1;
    vector<int> memo2;

    int rob(vector<int>& nums) {
        memo1.resize(nums.size(), -1);
        memo2.resize(nums.size(), -1);
        if (nums.size() == 1) return nums[0];
        return max(dfs(nums, memo1, true, 0), dfs(nums, memo2, false, 1));
    }

    int dfs(vector<int>& nums, vector<int>& memo, bool flag, int i)
    {
        if ( i >= nums.size() || (flag && i == nums.size() - 1) ) return 0;
        if ( memo[i] != -1 ) return memo[i];

        memo[i] = max(nums[i] + dfs(nums, memo, flag, i + 2), dfs(nums, memo, flag, i + 1));
        return memo[i];
    }
};
