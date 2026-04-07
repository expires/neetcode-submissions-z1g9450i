class Solution {
    map<int, vector<char>> nc =
        {
            {2, {'a', 'b', 'c'}},
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}}
        };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string cur;
        backtrack(res, digits, cur, 0);
        return res;
    }

    void backtrack(vector<string>& res, string digits, string& cur, int i)
    {
        
        if (cur.size() == digits.size() && cur != "")
        {
            res.push_back(cur);
            return;
        }


        for (char c : nc[digits[i] - '0']) {
            cur += c;
            backtrack(res, digits, cur, i + 1);
            cur.pop_back();
        }
    }
};
