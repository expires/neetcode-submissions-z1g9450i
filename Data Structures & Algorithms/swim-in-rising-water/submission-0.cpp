class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
    
        minHeap.push({grid[0][0], 0, 0});
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!minHeap.empty())
        {
            auto [t, r, c] = minHeap.top(); minHeap.pop();
            if (grid[r][c] == -1) continue;
            grid[r][c] = -1;
            if (r == n-1 && c == n-1) return t;

            for (auto& d : dirs) {
                int rn = r + d[0];
                int cn = c + d[1];

                if (rn < 0 || rn >= n || cn < 0 || cn >= n) continue;
                minHeap.push({max(t, grid[rn][cn]), rn, cn});

            }
        }
        return -1;
    }
};
