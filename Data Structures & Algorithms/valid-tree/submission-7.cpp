class Solution {
    unordered_map<int, vector<int>> adjMap;
    unordered_set<int> visited;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++){
            adjMap[edges[i][0]].push_back(edges[i][1]);
            adjMap[edges[i][1]].push_back(edges[i][0]);
        }


        if (!dfs(0, -1)) return false;

        return visited.size() == n;
    }

    bool dfs(int n, int parent)
    {
        if (visited.count(n)) return false;

        visited.insert(n);
        for (int p : adjMap[n])
        {
            if (p == parent) continue;
            if (!dfs(p, n)) return false;
        }

        return true;
    }
};
