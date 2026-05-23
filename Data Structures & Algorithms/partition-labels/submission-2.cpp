class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> freq;
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]] = i;
        }


        int start = 0;
        int end = freq[s[0]];

        vector<int> res;

        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, freq[s[i]]);
            if (i == end) 
            {
                res.push_back((i - start + 1));
                start = i + 1;
                continue;
            }
            
        }

        return res;

    }
};
