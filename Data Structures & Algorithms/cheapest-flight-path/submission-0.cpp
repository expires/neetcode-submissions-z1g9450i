class Solution {
    struct Node
    {
        int dest;
        int price;
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int,int, int>>, greater<>> minHeap;
    unordered_map<int, vector<Node>> adj;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for (auto f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        minHeap.push({0, src, 0});

        while (!minHeap.empty())
        {
            auto [price, node, stops] = minHeap.top(); minHeap.pop();
            if (node == dst) return price;
            if (stops > k) continue;
            for (auto d : adj[node])
            {                
                minHeap.push({price + d.price, d.dest, stops + 1});

            }
        }

        return -1;
    }
};
