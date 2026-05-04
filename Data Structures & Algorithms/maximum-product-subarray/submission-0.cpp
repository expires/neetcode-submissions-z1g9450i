class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0], res = nums[0];
    
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            int temp = curMax;
            curMax = max({num, curMax * num, curMin * num});
            curMin = min({num, temp * num, curMin * num});
            res = max(res, curMax);
        }
        
        return res;
    }
    
};
