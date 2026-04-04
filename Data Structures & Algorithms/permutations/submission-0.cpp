class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        backtrack(nums, res, cur, used);
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, vector<bool>& used)
    {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }


        for (int j = 0; j < nums.size(); j++) {
            if (used[j]) continue;
            used[j] = true;
            cur.push_back(nums[j]);
            backtrack(nums, res, cur, used);
            cur.pop_back();
            used[j] = false;  // undo
        }
    }
};