class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> v(n, 1);

        for (int i = 1; i < n; i++)
        {
            v[i] = nums[i - 1] * v[i - 1];
        }

        int postfix = 1;
        for (int i = (n-1); i >= 0; i--)
        {
            v[i] *= postfix;
            postfix *= nums[i];
        }

        return v;
    }
};
