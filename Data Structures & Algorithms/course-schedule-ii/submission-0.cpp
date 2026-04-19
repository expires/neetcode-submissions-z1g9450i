class Solution {
    unordered_map<int, vector<int>> pre;
    unordered_set<int> visited;
    unordered_set<int> visiting;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        for (int c = 0; c < prerequisites.size(); c++)
        {
            int course = prerequisites[c][0];
            int prereq = prerequisites[c][1];
            pre[course].push_back(prereq);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c, res))
            {
                return {};
            }
        }

        return res;
    }

    bool dfs(int course, vector<int>& res)
    {
        if (visiting.count(course)) return false; 
        if (visited.count(course)) return true;   

        visiting.insert(course);
        for (int p : pre[course])
        {
            if (!dfs(p, res)) return false;
        }
        visited.insert(course);
        visiting.erase(course);
        pre[course].clear();
        res.push_back(course);
        return true;
    }
};
