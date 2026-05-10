class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));

        return dfs(memo, coins, 0, amount);
    }
    
    int dfs(vector<vector<int>>& memo, vector<int>& coins, int i, int cur)
    {
        if (cur == 0) return 1;
        if (i >= coins.size()) return 0;
        if (memo[i][cur] != -1) return memo[i][cur];

        int res = 0;
        if (cur >= coins[i])
        {
            res = dfs(memo, coins, i + 1, cur);
            res+= dfs(memo, coins, i, cur - coins[i]);
        }
        memo[i][cur] = res;

        return res;

    }
};
