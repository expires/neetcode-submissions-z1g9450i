class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = nums[0];
        int l = 1; int r = nums.size() - 1;
        

        while (l<=r)
        {
            int mid = l + ((r - l) / 2);
            if (nums[mid] > min)
            {
                l = mid + 1;
            }
            else if (nums[mid] < min)
            {
                min = nums[mid];
                r = mid - 1;
            }
        }

        return min;
    }
};
