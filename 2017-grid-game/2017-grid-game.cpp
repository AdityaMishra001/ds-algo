class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> prefix(2, vector<long long>(n + 1, 0));
        for (int r = 0; r < 2; r++) {
            for (int c = 1; c <= n; c++) {
                prefix[r][c] = prefix[r][c - 1] + grid[r][c - 1];
            }
        }
        

        long long second=LLONG_MAX;
        for (int c = 0; c < n; c++) {
            // score is 
            // 0to c row1 
            // or 
            // c+1 to n-1 roe0
            second =min(second,max(prefix[1][c],prefix[0][n]-prefix[0][c+1]));
        }

        return second;
    }
};