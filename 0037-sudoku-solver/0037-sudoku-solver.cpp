class Solution {
public:
    vector<vector<char>> ans;

    bool solve(vector<vector<char>>& board, vector<int>& rowMask,
               vector<int>& colMask, vector<int>& gridMask, int r, int c) {
        if (c == 9) {
            return 1;
        }

        if (board[r][c] != '.') {
            if (r == 8) {
                return solve(board, rowMask, colMask, gridMask, 0, c + 1);
            } else {
                return solve(board, rowMask, colMask, gridMask, r + 1, c);
            }
        }

        int g = (r / 3) * 3 + (c / 3);

        for (int val = 1; val <= 9; val++) {
            int bit = (1 << (val - 1));

            if ((rowMask[r] & bit) || (colMask[c] & bit) || (gridMask[g] & bit))
                continue;

            board[r][c] = val + '0';
            rowMask[r] |= bit;
            colMask[c] |= bit;
            gridMask[g] |= bit;

            if (r == 8) {
                if (solve(board, rowMask, colMask, gridMask, 0, c + 1))
                    return 1;
            } else {
                if (solve(board, rowMask, colMask, gridMask, r + 1, c))
                    return 1;
            }

            board[r][c] = '.';
            rowMask[r] ^= bit;
            colMask[c] ^= bit;
            gridMask[g] ^= bit;
        }

        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rowMask(9);
        vector<int> colMask(9);
        vector<int> gridMask(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';

                    // Setting bits
                    rowMask[i] |= (1 << (val - 1));
                    colMask[j] |= (1 << (val - 1));
                    gridMask[(i / 3) * 3 + (j / 3)] |= (1 << (val - 1));
                }
            }
        }

        solve(board, rowMask, colMask, gridMask, 0, 0);

        return;
    }
};