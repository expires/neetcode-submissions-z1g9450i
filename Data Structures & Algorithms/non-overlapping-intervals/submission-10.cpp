class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
        
        int prev = intervals[0][1];
        int rem = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prev){
                rem++;
            }
            else 
            {
                prev = intervals[i][1];
            }
            
        }

        return rem;
    }
};
