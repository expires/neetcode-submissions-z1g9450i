class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        return mst(points);
    }

    int mst(vector<vector<int>>& points)
    {
        int total = 0;
        unordered_set<int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0, 0}); // {cost, node index}

        while (visited.size() < points.size()) {
            auto [cost, i] = minHeap.top(); minHeap.pop();
            if (visited.count(i)) continue;
            visited.insert(i);
            total += cost;
            
            // push all edges to unvisited nodes
            for (int j = 0; j < points.size(); j++) {
                if (!visited.count(j)) {
                    int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                    minHeap.push({dist, j});
                }
            }
        }
        return total;
    }
};
