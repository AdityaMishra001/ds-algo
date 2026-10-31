class Solution {
    static inline int MOD = 1e9 + 7;
public:
    
    int uniquePaths(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        dp[0][0][0]=1;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0){
                    int ways=(1LL*dp[r][c][0]+dp[r][c][1])%MOD;
                    if(c+1<n){
                        dp[r][c+1][1]= (1LL*dp[r][c+1][1]+ways)%MOD;
                    }
                    if(r+1<m){
                        dp[r+1][c][0]= (1LL*dp[r+1][c][0]+ways)%MOD;
                    }

                }else{
                    if(c+1<n){
                        dp[r][c+1][1]= (1LL*dp[r][c+1][1]+dp[r][c][0])%MOD;
                    }
                    if(r+1<m){
                        dp[r+1][c][0]= (1LL*dp[r+1][c][0]+dp[r][c][1])%MOD;
                    }
                }
           }
        }

        return (1LL*dp[m-1][n-1][0]+dp[m-1][n-1][1])%MOD;
    }
};