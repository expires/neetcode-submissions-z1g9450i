class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int max1 = 0;

        while (l < r)
        {
            int width = r - l;
            int height = min(heights[l], heights[r]);
            int area = width * height;

            max1 = max(area, max1);

            if (heights[l] < heights[r])
                l++;
            else
                r--;
            

        }

        return max1;
    }
};
