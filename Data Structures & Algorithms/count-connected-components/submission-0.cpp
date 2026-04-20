class Solution {
    unordered_map<int, vector<int>> adjMap;
    unordered_set<int> visited;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        for (auto& p : edges)
        {
            adjMap[p[0]].push_back(p[1]);
            adjMap[p[1]].push_back(p[0]); 
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited.count(i)) {
                connectedDfs(i);
                count++;
            }
        }

        return count;
    }

    bool connectedDfs(int n)
    {
        if (!adjMap.count(n)) return true;
        if (visited.count(n)) return false;

        visited.insert(n);

        for (int i = 0; i < adjMap[n].size(); i++)
        {
            if (connectedDfs(adjMap[n][i])) return true;
        }
        
        return false;
    }

};
