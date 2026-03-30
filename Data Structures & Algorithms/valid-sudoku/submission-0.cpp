class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row, cols;
        map<pair<int , int>, unordered_set<char>> squares;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                
                if (board[i][j] == '.') continue;

                pair<int, int> k = {i / 3, j / 3};
                if (row[i].count(board[i][j])) return false;
                if (cols[j].count(board[i][j])) return false;
                if (squares[k].count(board[i][j])) return false;

                row[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squares[k].insert(board[i][j]);
                

            }
        }

        return true;
    }
};
