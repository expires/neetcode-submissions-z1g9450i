class Solution {
public:
    vector<int> memo;

    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount + 1, -2);
        if (amount == 0) return 0;

        return dfs(coins, amount, 0);
    }
    
    int dfs(vector<int>& coins, int amount, int total)
    {
        if (total > amount) return -1;
        if (total == amount) return 0;
        
        int res = INT_MAX;

        if (memo[total] != -2) return memo[total];

        for (int j = 0; j < coins.size(); j++)
        {
            if ((long)total + coins[j] > amount) continue;
            int result = dfs(coins, amount, total + coins[j]);
            if (result != -1)
                res = min(res, 1 + result);
            
        }

        memo[total] = res == INT_MAX ? -1 : res;
        return memo[total];
    }
};
