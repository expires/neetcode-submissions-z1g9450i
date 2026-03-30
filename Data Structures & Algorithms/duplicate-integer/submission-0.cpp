class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        set<int> s;

        for (int r = 0; r < nums.size(); r++)
        {
            if ( s.count(nums[r]) > 0 )
            {
                return true;
            }
            else
            {
                s.insert(nums[r]);
            }

        }

        return false;

    }
};