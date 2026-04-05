class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(res, nums, cur, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur,  int i)
    {

        res.push_back(cur);  // record at every level
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue;  // skip dups
            cur.push_back(nums[j]);
            backtrack(res, nums, cur, j + 1);
            cur.pop_back();
        }
    }
};
