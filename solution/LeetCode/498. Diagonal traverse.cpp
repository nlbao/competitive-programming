class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int nRow = matrix.size();
        if (nRow == 0) return ans;
        int nCol = matrix[0].size();
        if (nCol == 0) return ans;

        bool isUp = true;
        int x = 0, y = 0, n = nRow*nCol;
        while (n > 0) {
            if (isUp) {
                int xx, yy;
                while (x >= 0 && y >= 0 && x < nRow && y < nCol) {
                    xx = x, yy = y;
                    ans.push_back(matrix[x][y]);
                    --n;
                    --x, ++y;

                }
                x = xx, y = yy;
                if (y < nCol-1) ++y;
                else ++x;
            }
            else {
                int xx, yy;
                while (x >= 0 && y >= 0 && x < nRow && y < nCol) {
                    xx = x, yy = y;
                    ans.push_back(matrix[x][y]);
                    --n;
                    ++x, --y;

                }
                x = xx, y = yy;
                if (x < nRow-1) ++x;
                else ++y;
            }
            isUp = !isUp;
        }

        return ans;
    }
};