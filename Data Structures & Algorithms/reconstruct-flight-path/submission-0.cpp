class Solution {
    unordered_map<string, vector<string>> adj;
    vector<string> result;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t: tickets)
        {
            adj[t[0]].push_back(t[1]);
        }

        for (auto& [node, neighbors] : adj)
        {
            sort(neighbors.begin(), neighbors.end());
        }

        dfs("JFK");
        reverse(result.begin(), result.end());

        return result;
    }

    void dfs(string node) {
        while (!adj[node].empty()) {
            string next = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            dfs(next);
        }
        result.push_back(node);
    }
};
