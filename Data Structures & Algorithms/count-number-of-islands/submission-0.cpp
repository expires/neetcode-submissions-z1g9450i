class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[r].size(); c++)
            {
                if (grid[r][c] == '1')
                {
                    dfs(grid, r, c);
                    num++;
                }
            }
        }

        return num;
    }

    void dfs(vector<vector<char>>& grid, int r, int c )
    {
        if (r < 0 || r >= grid.size()) return;
        if (c < 0 || c >= grid[0].size()) return;
        if (grid[r][c] == '0' || grid[r][c] == '#') return;
        
        grid[r][c] = '#';
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
    }
};
