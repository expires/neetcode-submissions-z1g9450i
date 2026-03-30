class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> seen;

        int l = 0;
        int r = 0;

        int longest = 0;

       while (r < s.size()) {
            if (seen.count(s[r])) {
                l = max(l, seen[s[r]] + 1);
            }
            seen[s[r]] = r;
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;

    }
};
