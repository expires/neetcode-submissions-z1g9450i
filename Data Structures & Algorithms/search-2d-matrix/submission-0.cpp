class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;

        int l = 0; int r = matrix.size() - 1;
        int row = -1;

        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            int s = matrix[mid].size() - 1;
            if (matrix[mid][0] <= target && target <= matrix[mid][s])
            {
                row = mid;
                break;
            }
            else if (matrix[mid][0] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << row;

        if (row != -1)
        {
            l = 0; r = matrix[row].size();
            while (l <= r)
            {
                int mid = l + ((r - l) / 2);
                if (matrix[row][mid] == target)
                {
                    found = true;
                    break;
                }
                else if (matrix[row][mid] > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }


        return found;
    }
};
