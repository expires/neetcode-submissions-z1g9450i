class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        vector<int> sortedQ = queries;
        sort(sortedQ.begin(), sortedQ.end());
        
        unordered_map<int, int> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        int i = 0;
        
        for (int q : sortedQ) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int size = intervals[i][1] - intervals[i][0] + 1;
                minHeap.push({size, intervals[i][1]});
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < q)
                minHeap.pop();
            
            res[q] = minHeap.empty() ? -1 : minHeap.top().first;
        }
        
        vector<int> output;
        for (int q : queries)
            output.push_back(res[q]);
        
        return output;
    }
};