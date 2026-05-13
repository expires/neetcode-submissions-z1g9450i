class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
        return dfs(memo, s, t, 0, 0);
    }

    int dfs(vector<vector<int>>& memo, string& s, string& t, int a, int b)
    {
        if (b >= t.size()) return 1;
        if (a >= s.size()) return 0;
        if (memo[a][b] != -1) return memo[a][b];
        
        int res = 0;

        if (s[a] == t[b])
        {
            res += dfs(memo, s, t, a + 1, b + 1);
        }
        res += dfs(memo, s, t, a + 1, b);

        memo[a][b] = res;
        return memo[a][b];
    }
};
