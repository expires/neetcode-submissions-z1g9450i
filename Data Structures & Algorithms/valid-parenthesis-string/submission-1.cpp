class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;

        for (char c : s)
        {
            if (c == '(') { min++; max++; }
            if (c == ')') { min--; max--; }
            if (c == '*') { min--; max++; }

            if (max < 0) return false;

            min = (min < 0) ? 0 : min;
        }

        return min == 0;
    }
};
