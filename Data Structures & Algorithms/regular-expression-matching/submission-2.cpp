class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size() + 1, vector<int> (p.size() + 1, -1));
        return dfs(memo, s, p, 0, 0);
    }

    bool dfs(vector<vector<int>>& memo, string& s, string& p, int a, int b)
    {
        if (b >= p.size()) return a >= s.size();
        if (a >= s.size()) {
            return b + 1 < p.size() && p[b+1] == '*' && dfs(memo, s, p, a, b+2);
        }
        if (memo[a][b] != -1) return memo[a][b];
        
        bool match = (s[a] == p[b] || p[b] == '.');

        if (b + 1 < p.size() && p[b+1] == '*') {
            return dfs(memo, s, p, a, b+2) ||
                (match && dfs(memo, s, p, a+1, b));   
        }

        if (match)
            return dfs(memo, s, p, a+1, b+1);

        memo[a][b] = match;

        return false;
    }
};
