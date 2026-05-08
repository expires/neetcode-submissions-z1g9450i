class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));

        return dfs(text1, text2, 0, 0, memo);

    }

    int dfs(string& t1, string& t2, int i, int j, vector<vector<int>>& memo) {
        if (i == t1.size() || j == t2.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (t1[i] == t2[j])
        memo[i][j] = 1 + dfs(t1, t2, i+1, j+1, memo);
        else
            memo[i][j] = max(dfs(t1, t2, i+1, j, memo), dfs(t1, t2, i, j+1, memo));
        
        return memo[i][j];
    }
};
