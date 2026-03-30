class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size()) return false;

        int a[26] = {0};
        int b[26] = {0};
        
        for (int i = 0; i < s1.size(); i++)
        {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }

        int matches = 0;

        for (int i = 0; i < 26; i++)
        {
            if (a[i] == b[i])
            {
                matches++;
            }
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++)
        {
            if (matches == 26) return true;

            int i = s2[r] - 'a';
            b[i]++;

            if (a[i] == b[i])
            {
                matches++;
            } else if (a[i] + 1 == b[i])
            {
                matches--;
            }

            i = s2[l] - 'a';
            b[i]--;

            if (a[i] == b[i])
            {
                matches++;
            } else if (a[i] - 1 == b[i])
            {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};
