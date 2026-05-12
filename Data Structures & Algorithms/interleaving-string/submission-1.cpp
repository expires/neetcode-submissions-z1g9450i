class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ( s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(memo, s1, s2, 0, 0, s3);
    }

    bool dfs(vector<vector<int>>&memo, string& s1, string& s2, int a, int b, string& s3)
    {
        if (a + b == s3.size()) return true;
        if (memo[a][b] != -1) return memo[a][b];
        
        bool cres = false;

        if (a < s1.size() && s1[a] == s3[a+b])
        {
            cres = dfs(memo, s1, s2, a + 1, b, s3);
        }

        if (!cres && b < s2.size() && s2[b] == s3[a+b])
        {
            cres = dfs(memo, s1, s2, a, b + 1, s3);
        }

        memo[a][b] = cres;
        return cres;
    }
};
