class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxRes = 0;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                if (grid[r][c] == 1)
                {
                    maxRes = max(maxRes, dfs(grid, 1, r, c));
                }
            }
        }

        return maxRes;
    }

    int dfs(vector<vector<int>>& grid, int n, int r, int c)
    {
        if ( r < 0 || r >= grid.size() ) return 0;
        if ( c < 0 || c >= grid[0].size() ) return 0;
        if ( grid[r][c] != n ) return 0;
        
        grid[r][c] = -1;
        
        return 1 + dfs(grid, n, r + 1, c) 
            + dfs(grid, n, r - 1, c)
            + dfs(grid, n, r, c + 1)
            + dfs(grid, n, r, c - 1);

    }
};
