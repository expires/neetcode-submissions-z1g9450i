class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int target = total / 2;

        unordered_set<int> dp;
        dp.insert(0);

        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> dpx;
            for (auto j: dp)
            {
                dpx.insert(j + nums[i]);
                dpx.insert(j);
                if (j == target) return true;
            }
            dp = dpx;
        }


        
        return false;
    }

};
