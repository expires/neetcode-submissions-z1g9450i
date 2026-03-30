class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() - 1;
        int l = 0;

        vector<int> rtn;

        while (l <= n)
        {
            int sum = numbers[l] + numbers[n];

            if (sum > target)
            {
                n--;
            }

            if (sum < target)
            {
                l++;
            }

            if (sum == target)
            {
                rtn.push_back(l + 1);
                rtn.push_back(n + 1);
                break;
            }

        }
        
        return rtn;
        
    }
};
