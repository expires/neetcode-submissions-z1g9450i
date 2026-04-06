class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtrack(res, cur, s, 0);
        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& cur, string s, int i)
    {
        if (i == s.size())
        {
            res.push_back(cur);
            return;
        };

        for (int j = i; j < s.size(); j++)
        {
            string sub = s.substr(i, j - i + 1);
            if (isPalindrome(sub))
            {
                cur.push_back(sub);
                backtrack(res, cur, s, j + 1);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};
