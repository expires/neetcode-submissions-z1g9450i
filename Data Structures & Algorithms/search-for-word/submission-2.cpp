class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        string cur;

        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[r].size(); c++)
            {
                if (backtrack(board, word, cur, 0, c, r)) return true;
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, string& cur, int i, int c, int r)
    {
        if (i == word.size()) return true;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return false;
        if (board[r][c] != word[i]) return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = backtrack(board, word, cur, i + 1, c + 1, r) ||
                     backtrack(board, word, cur, i + 1, c - 1, r) ||
                     backtrack(board, word, cur, i + 1, c, r + 1) ||
                     backtrack(board, word, cur, i + 1, c, r - 1);
        board[r][c] = temp;
        return found;


    }
};
