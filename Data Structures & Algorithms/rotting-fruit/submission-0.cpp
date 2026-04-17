class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) q.push({r, c});
                if (grid[r][c] == 1) fresh++;
            }
        }

        int mins = 0;
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();

                int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) continue;
                    if (grid[nr][nc] != 1) continue;
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }
            mins++;
        }

        return fresh == 0 ? mins : -1;
    }
};
