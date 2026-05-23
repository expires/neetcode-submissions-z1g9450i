class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        
        vector<int> res(3, 0);

        for (auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            for (int i = 0; i < 3; i++)
                res[i] = max(res[i], t[i]);
        }

        return res == target;
    }
};
