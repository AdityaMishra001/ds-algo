class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bitset<1024>> dp(n);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0){
                    dp[0].set(grid[0][0]);
                    continue;
                }
                bitset<1024>curr;
                // top
                if (row > 0) {
                    for (int k = 0; k < 1024; k++) {
                        if (dp[col][k]) {
                            curr.set(k ^ grid[row][col]);
                        }
                    }
                }
                // left
                if (col > 0) {
                    for (int k = 0; k < 1024; k++) {
                        if (dp[col - 1][k]) {
                            curr.set(k ^ grid[row][col]);
                        }
                    }
                }
                dp[col]=curr;
            }
        }

        for (int k = 0; k < 1024; k++) {
            if (dp[n-1][k])
                return k;
        }
        return 1024;
    }
};