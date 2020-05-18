class Solution {
public:
    static const int MAX_N = 501;
    static const int MAX_MINES = 5001;
    vector<vector<int>> is_mine;
    int cLeft[MAX_N][MAX_N], cRight[MAX_N][MAX_N], cTop[MAX_N][MAX_N], cBot[MAX_N][MAX_N];

    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int ans = 0;
        is_mine = vector<vector<int>>(N, vector<int>(N, false));
        int nMine = (int)mines.size();
        for (int i = 0; i < nMine; ++i) {
            int x = mines[i][0], y = mines[i][1];
            is_mine[x][y] = true;
        }
        // row
        for (int row = 0; row < N; ++row) {
            // left
            cLeft[row][0] = 1 - int(is_mine[row][0]);
            for (int col = 1; col < N; ++col)
                cLeft[row][col] = is_mine[row][col] ? 0 : cLeft[row][col-1] + 1;
            // right
            cRight[row][N-1] = 1 - int(is_mine[row][N-1]);
            for (int col = N-2; col >= 0; --col)
                cRight[row][col] = is_mine[row][col] ? 0 : cRight[row][col+1] + 1;
        }
        // col
        for (int col = 0; col < N; ++col) {
            // top
            cTop[0][col] = 1 - int(is_mine[0][col]);
            for (int row = 1; row < N; ++row)
                cTop[row][col] = is_mine[row][col] ? 0 : cTop[row-1][col] + 1;
            // bot
            cBot[N-1][col] = 1 - int(is_mine[N-1][col]);
            for (int row = N-2; row >= 0; --row)
                cBot[row][col] = is_mine[row][col] ? 0 : cBot[row+1][col] + 1;
        }
        // cal ans
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k) {
                // cout << i << " " << k << " : " << is_mine[i][k] << ", " << cTop[i][k] << " " << cBot[i][k] << " " << cLeft[i][k] << " " << cRight[i][k] << endl;
                int x = min(min(cTop[i][k], cBot[i][k]), min(cLeft[i][k], cRight[i][k]));
                ans = max(ans, x);
            }
        return ans;
    }
};