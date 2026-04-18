class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int r = 0; r < m; r++) {
            dfsMarkSafe(board, r, 0);
            dfsMarkSafe(board, r, n-1);        }
        for (int c = 0; c < n; c++) {
            dfsMarkSafe(board, 0, c);
            dfsMarkSafe(board, m-1, c);
        }

        for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 'O') board[r][c] = 'X'; 
            else if (board[r][c] == 'T') board[r][c] = 'O';  
        }


    }

    void dfsMarkSafe(vector<vector<char>>& board, int r, int c)
    {
        if (r < 0 || r >= board.size()) return;
        if (c < 0 || c >= board[0].size()) return;

        if (board[r][c] == 'O')
        {
            board[r][c] = 'T';
            dfsMarkSafe(board, r + 1, c);
            dfsMarkSafe(board, r - 1, c);
            dfsMarkSafe(board, r, c + 1);
            dfsMarkSafe(board, r, c - 1);
        }        
    }
};
