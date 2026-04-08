class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);
        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& board, int i)
    {
        if (i == board.size())
        {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < board.size(); c++)
        {
            if (isSafe(i, c, board))
            {
                board[i][c] = 'Q';
                backtrack(res, board, i + 1);
                board[i][c] = '.';
            }
        }

    }

    bool isSafe(int r, int c, vector<string>& board)
    {
        int n = board[0].size();
        for (int i = 0; i < n; i++)
        {
            if (i == r) continue;
            if (board[i][c] == 'Q') return false;
        }

        int i = r - 1, j = c - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--; j--;
        }

        i = r - 1; j = c + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') return false;
            i--; j++;
        }

        return true;
    }
};
