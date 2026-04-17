class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        for (int r = 0; r < m; r++) {
            dfs(heights, pac, r, 0, heights[r][0]);
            dfs(heights, atl, r, n-1, heights[r][n-1]);
        }
        for (int c = 0; c < n; c++) {
            dfs(heights, pac, 0, c, heights[0][c]);
            dfs(heights, atl, m-1, c, heights[m-1][c]);
        }

        vector<vector<int>> res;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (pac[r][c] && atl[r][c])
                    res.push_back({r, c});
        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int prev) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (visited[r][c]) return;
        if (heights[r][c] < prev) return;

        visited[r][c] = true;
        dfs(heights, visited, r+1, c, heights[r][c]);
        dfs(heights, visited, r-1, c, heights[r][c]);
        dfs(heights, visited, r, c+1, heights[r][c]);
        dfs(heights, visited, r, c-1, heights[r][c]);
    }
};