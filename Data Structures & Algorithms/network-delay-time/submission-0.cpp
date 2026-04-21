class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int,int>>> graph;  // node -> {neighbor, weight}
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        unordered_set<int> visited;

        for (auto& t : times)
        {
            graph[t[0]].push_back({t[1], t[2]});
        }

        minHeap.push({0, k}); // {time, node}
        dist[k] = 0;

        while (!minHeap.empty()) {
            auto [d, node] = minHeap.top(); minHeap.pop();
            if (visited.count(node)) continue;
            visited.insert(node);
            for (auto& [neighbor, weight] : graph[node]) {
                if (d + weight < dist[neighbor]) {
                    dist[neighbor] = d + weight;
                    minHeap.push({dist[neighbor], neighbor});
                }
            }
        }

        

        int maxDist = *max_element(dist.begin() + 1, dist.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }


    
};
