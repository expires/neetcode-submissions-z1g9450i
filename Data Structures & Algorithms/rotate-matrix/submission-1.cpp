class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        for (int r = 0; r < matrix.size(); r++)
        {
            for (int c = r + 1; c < matrix.size(); c++)
            {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            } 
        }

        for (int r = 0; r < matrix.size(); r++)
            reverse(matrix[r].begin(), matrix[r].end());

    }
};
