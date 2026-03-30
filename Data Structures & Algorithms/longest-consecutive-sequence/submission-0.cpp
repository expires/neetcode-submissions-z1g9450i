class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());


        int longest = 0;
        for (int i = 0; i < n; i++)
        {
            if (!(s.count(nums[i] - 1)))
            {
                int cur = 1;
                int j = 1;
                while (s.count(nums[i] + j))
                {
                    j++;
                    cur++;
                }

                longest = (longest < cur) ? cur : longest;
            }
        }

        return longest;
    }
};
