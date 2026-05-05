class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.size(), false);
        memo[0] = true;

        for (int i = 0; i <= s.size(); i++) {
            if (!memo[i]) continue;
            for (string& word : wordDict) {
                if (s.substr(i, word.size()) == word)
                    memo[i + word.size()] = true;
            }
        }

        return memo[s.size()];

    }
};
