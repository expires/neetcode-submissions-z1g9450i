class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int>(2, -1));

        if (prices.size() <= 1) return 0;
        return dfs(prices, 0, false, memo);
    }

    int dfs(vector<int>& prices, int i, bool holding, vector<vector<int>>& memo)
    {
        if (i >= prices.size()) return 0;
        if (memo[i][holding] != -1) return memo[i][holding];
        int result;
        if (holding)
        {
            result = max(
                prices[i] + dfs(prices, i + 2, false, memo), 
                dfs(prices, i + 1, true, memo)                 
            );
        }
        else
        {
            result = max(-prices[i] + dfs(prices, i + 1, true, memo), dfs(prices, i + 1, false, memo));
        }

        memo[i][holding] = result;
        return memo[i][holding];
    }
};
