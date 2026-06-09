/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() <= 1) return true;

        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });

        Interval prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < prev.end)
            {
                return false;
            }
            prev = intervals[i];
        }

        return true;
    }
};
