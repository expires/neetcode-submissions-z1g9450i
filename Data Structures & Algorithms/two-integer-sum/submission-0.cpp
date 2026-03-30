class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!seen.count(nums[i]))
            {
                seen.insert({nums[i], i});
            }
            
            int needed = target - nums[i];

            if (seen.count(needed) && seen[needed] != i)
            {
                return {seen[needed], i};
            }
        }

        return {};

    }
};
