class Solution {
    unordered_map<int, vector<int>> adjMap;
    unordered_set<int> visited;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2, 0);

        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            visited.clear();
            if (dfs(a, b, -1)) return edge; 
            
            adjMap[a].push_back(b);
            adjMap[b].push_back(a);
        }

        return res;
    }

    bool dfs(int curr, int target, int parent) {
        if (curr == target) return true;
        visited.insert(curr);
        for (int neighbor : adjMap[curr]) {
            if (neighbor == parent) continue;
            if (!visited.count(neighbor))
                if (dfs(neighbor, target, curr)) return true;
        }
        return false;
    }
};
