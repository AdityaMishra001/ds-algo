class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bitset<1024>>>dp(m,vector<bitset<1024>>(n));
        dp[0][0].set(grid[0][0]);

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row==0&&col==0)continue;
                //top
                if(row>0){
                    for(int k=0;k<1024;k++){
                        if(dp[row-1][col][k]){
                            dp[row][col].set(k^grid[row][col]);
                        }
                    }
                }
                //left
                if(col>0){
                    for(int k=0;k<1024;k++){
                        if(dp[row][col-1][k]){
                            dp[row][col].set(k^grid[row][col]);
                        }
                    }
                }
            }
        }

        for(int k=0;k<1024;k++){
            if(dp[m-1][n-1][k])return k;
        }
        return 1024;
    }
};