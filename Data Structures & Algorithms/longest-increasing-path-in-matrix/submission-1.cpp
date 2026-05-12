class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size() + 1, vector<int>(matrix[0].size() + 1, -1));
        int mx = 0;

        for (int r = 0; r < matrix.size(); r++)
        {
            for(int c = 0; c < matrix[0].size(); c++)
            {
                mx = max(mx, dfs(memo, matrix, r, c));
            }
        }

        return mx;

    }

    int dfs(vector<vector<int>>& memo, vector<vector<int>>& matrix, int r, int c)
    {
        if ( r >= matrix.size() || r < 0) return 0;
        if ( c >= matrix[0].size() || c < 0) return 0;
        if (memo[r][c] != -1) return memo[r][c];

        int res = 1;


        if (r+1 < matrix.size() && matrix[r+1][c] > matrix[r][c])
            res = max(res, 1 + dfs(memo, matrix, r+1, c));

        if (r-1 >= 0 && matrix[r-1][c] > matrix[r][c])
            res = max(res, 1 + dfs(memo, matrix, r-1, c));
        
        if (c+1 < matrix[0].size() && matrix[r][c+1] > matrix[r][c])
            res = max(res, 1 + dfs(memo, matrix, r, c+1));

        if (c-1 >= 0 && matrix[r][c-1] > matrix[r][c])
            res = max(res, 1 + dfs(memo, matrix, r, c-1));

        memo[r][c] = res;
        return memo[r][c];


    }
};
