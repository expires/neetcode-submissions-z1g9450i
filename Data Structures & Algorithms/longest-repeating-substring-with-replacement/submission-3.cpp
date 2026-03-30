class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> sc;

        int l = 0; int maxf = 0;
        int res = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            sc[s[i]]++;
            maxf = max(maxf, sc[s[i]]);

            while ((i - l + 1) - maxf > k)
            {
                sc[s[l]]--;
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};
