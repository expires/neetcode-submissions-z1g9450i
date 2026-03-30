class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (int i = 0; i < strs.size(); i++)
        {
            s += to_string(strs[i].size()) + '#' + strs[i];
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;         // find the '#'
            int len = stoi(s.substr(i, j-i)); // parse the length
            strs.push_back(s.substr(j+1, len)); // extract the word
            i = j + 1 + len;                  // move past it
        }

        return strs;

    }
};
