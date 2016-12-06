class Solution {
public:
    bool rowValid[9][10], colValid[9][10], bigCellValid[9][10];
    int a[9][9], bigCellID[9][9];


    bool isValid(int x, int y, int val) {
        return rowValid[x][val] && colValid[y][val]
            && bigCellValid[bigCellID[x][y]][val];
    }

    void writeCell(int x, int y, int val) {
        rowValid[x][val] = colValid[y][val] = false;
        bigCellValid[bigCellID[x][y]][val] = false;
        a[x][y] = val;
    }

    void eraseCell(int x, int y) {
        int val = a[x][y];
        rowValid[x][val] = colValid[y][val] = true;
        bigCellValid[bigCellID[x][y]][val] = true;
        a[x][y] = -1;
    }

    bool trying(int x, int y) {
        if (x >= 9) return true;
        if (y >= 9) return trying(x+1, 0);
        if (a[x][y] > -1) return trying(x, y+1);

        for (int val = 1; val <= 9; ++val) {
            if (isValid(x, y, val)) {
                writeCell(x, y, val);
                if (trying(x, y+1)) return true;
                eraseCell(x, y);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // init
        for (int i = 0; i < 9; ++i)
            for (int val = 1; val <= 9; ++val)
                colValid[i][val] = rowValid[i][val] = bigCellValid[i][val] = true;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                a[i][j] = board[i][j] == '.' ? -1 : board[i][j] - '0';
                bigCellID[i][j] = (i/3)*3 + (j/3);
                if (a[i][j] > -1) {
                    int val = a[i][j];
                    colValid[j][val] = rowValid[i][val] = false;
                    bigCellValid[bigCellID[i][j]][val] = false;
                }
            }
        }

        // recursive
        trying(0, 0);

        // get the answer
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.' && a[i][j] > -1)
                    board[i][j] = char(a[i][j] + int('0'));
    }
};