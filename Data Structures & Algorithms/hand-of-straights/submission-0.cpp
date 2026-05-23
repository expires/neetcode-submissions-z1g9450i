class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int,int> freq;

        for (int i = 0; i < hand.size(); i++)
        {
            freq[hand[i]]++;
        }

        for (auto& [key, val] : freq) {
            while (val > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (freq[key + i] == 0) return false;
                    freq[key + i]--;
                }
            }
        }

        return true;
    }
};
