class Solution {
    static inline vector<int>moves={-1,0,1,0,-1};
    bool dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int r,int c,int m,int n,int t){
        vis[r][c]=1;
        if(r==m-1 && c==n-1){
            return true;
        }
        
        for(int dir=0;dir<4;dir++){
            int nr=r+moves[dir];
            int nc=c+moves[dir+1];
            if(nr<0||nc<0||nr>=m||nc>=n||vis[nr][nc] ||grid[nr][nc]>t)continue;
            if( dfs(grid,vis,nr,nc,m,n,t) )
                return 1;
        }
        return 0;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int low=grid[0][0],high=0;
        for(auto row:grid)
            high=max(high,*max_element(row.begin(),row.end()));

        int minTime=high;
        while(low<=high){
            int trialTime=low+((high-low)>>1);
            vector<vector<bool>>vis(m,vector<bool>(n,0));
            if(dfs(grid,vis,0,0,m,n,trialTime)){
                minTime=trialTime;
                high=trialTime-1;
            }else{
                low=trialTime+1;
            }
        }
        return minTime;
    }
};