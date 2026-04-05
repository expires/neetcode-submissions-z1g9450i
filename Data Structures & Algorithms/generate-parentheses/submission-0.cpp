class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(0 , 0, n, res, s);
        return res;
    }

    void backtrack(int o, int c, int n, vector<string>& res, string& s)
    {
        if (o == c && o == n)
        {
            res.push_back(s);
            return;
        }

        if (o < n)
        {
            s += "(";
            backtrack(o + 1, c, n, res, s);
            s.pop_back();
        }
        if ( c < o )
        {
            s+= ")";
            backtrack(o, c + 1, n, res, s);
            s.pop_back();
        }
    }
};
