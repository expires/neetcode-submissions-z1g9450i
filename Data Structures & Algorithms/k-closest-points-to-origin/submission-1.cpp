class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> heap(cmp);
        
        for (vector<int> v : points)
        {
            heap.push({v[0], v[1]});

            if (heap.size() > k)
            {
                heap.pop();
            }
        }

        vector<vector<int>> res;

        for (int i = 0; i < k; i++)
        {
            pair<int, int> point = heap.top(); heap.pop();
            res.push_back({point.first, point.second});
        }

        return res;
        
    }
};
