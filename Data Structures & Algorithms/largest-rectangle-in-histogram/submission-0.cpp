class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int mA = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i]))
            {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                mA = max(mA, height * width);
            } 
            s.push(i);
        }

        return mA;
    }
};
