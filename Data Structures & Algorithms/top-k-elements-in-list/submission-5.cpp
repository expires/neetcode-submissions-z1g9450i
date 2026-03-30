class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) m[n]++;

        for (const auto& [n, f] : m) {
            freq[f].push_back(n);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0 && res.size() < k; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) break;
            }
        }

        return res;

    }
};
