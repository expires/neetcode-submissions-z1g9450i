class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(candidates, res, cur, 0, target, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& cur, int i, int target, int total)
    {
        if (total == target)
        {            
            res.push_back(cur);
            return;
        }
        
        for (int j = i; j < candidates.size(); j++)
        { 
            if (j > i && candidates[j] == candidates[j-1]) continue;
            if (total + candidates[j] > target)
            {
                break;
            }
            cur.push_back(candidates[j]);
            backtrack(candidates, res, cur, j + 1, target, total + candidates[j]);
            cur.pop_back();
        }

    }
};
