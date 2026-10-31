class Solution {
    static inline int MOD = 1e9 + 7;
public:
    
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        dp[m-1][n-1][0]=1;
        dp[m-1][n-1][1]=1;

        for(int r=m-1;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                if(r==m-1&&c==n-1)continue;
                else if(grid[r][c]==1){
                    //row move go down# r++
                    dp[r][c][1]=dp[r+1][c][0];
                    //!RM go right-->c++
                    dp[r][c][0]=dp[r][c+1][1];
                }
                else{
                    int ways=(1LL*dp[r][c+1][1]+dp[r+1][c][0])%MOD;
                    dp[r][c][0]=ways;
                    dp[r][c][1]=ways;
                }
            }
        }

        return dp[0][0][0];
    }
};