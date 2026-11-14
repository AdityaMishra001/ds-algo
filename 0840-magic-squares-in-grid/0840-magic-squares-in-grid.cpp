class Solution {
public:
    bool check(vector<vector<int>>& grid, int r, int c, int m, int n,
               vector<vector<bool>>& valid) {
        if (grid[r + 1][c + 1] != 5)
            return 0;

        bool seen[10] = {0};
        vector<int> rowSum(3, 0), colSum(3, 0);

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || seen[grid[i][j]]) {
                    return false;
                }

                rowSum[i - r] += grid[i][j];
                colSum[j - c] += grid[i][j];
                seen[grid[i][j]] = 1;
            }
            if (rowSum[i - r] != 15)
                return 0;
        }
        return (colSum[0] == 15 && colSum[1] == 15 && 15 == colSum[2]) &&
               (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] == 15) &&
               (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] == 15);
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ct = 0;
        vector<vector<bool>> valid(m, vector<bool>(n, 1));
        for (int r = 0; r <= m - 3; r++) {
            for (int c = 0; c <= n - 3; c++) {
                if (check(grid, r, c, m, n, valid)) {
                    ct++;
                }
            }
        }
        return ct;
    }
};