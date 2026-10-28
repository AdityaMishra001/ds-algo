class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<bitset<1024>>dp(m*n);
        dp[0].set(grid[0][0]);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                int curr= i*n+j;
                if(i>0){
                    int top=(i-1)*n+j;
                    for(int k=0;k<1024;k++){
                        if(dp[top][k])
                            dp[curr].set(k^grid[i][j]);//k->prevState(exors)
                    }
                }
                if(j>0){
                    int left=i*n+j-1;
                    for(int k=0;k<1024;k++){
                        if(dp[left][k])
                            dp[curr].set(k^grid[i][j]);
                    }
                }
            }
        }
       
        int destination=m*n-1;//(m-1)*n+(n-1)
        for(int k=0;k<1024;k++){
            if(dp[destination][k])return k;
        }
        return 1024;
    }
};