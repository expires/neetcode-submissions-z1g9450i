class Solution {
    unordered_map<int, vector<int>> pre;
    unordered_set<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int c = 0; c < prerequisites.size(); c++)
        {
            int course = prerequisites[c][0];
            int prereq = prerequisites[c][1];
            pre[course].push_back(prereq);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int course)
    {
        if (visited.count(course)) return false;
        if (pre[course].empty()) return true;

        visited.insert(course);
        for (int p : pre[course])
        {
            if (!dfs(p)) return false;
        }
        visited.erase(course);
        pre[course].clear();
        return true;
    }
};
