class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return dfs(memo, word1, word2, 0, 0);
    }

    int dfs(vector<vector<int>>& memo, string& p, string& k, int e, int i )
    {
        if (i >= k.size()) return p.size() - e;
        if (e >= p.size()) return k.size() - i;
        if (memo[e][i] != -1) return memo[e][i];

        if (p[e] == k[i])
        {
            return dfs(memo, p, k, e + 1, i + 1);
        }

        memo[e][i] = 1 + min({
            dfs(memo, p, k, e+1, i),
            dfs(memo, p, k, e, i+1), 
            dfs(memo, p, k, e+1, i+1) 
        });

        return memo[e][i];
    }
};
