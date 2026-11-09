class Solution {
    static inline vector<int>moves={-1,0,1,0,-1};
    using t=tuple<int,int,int>;
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<t,vector<t>,greater<t>>pq;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));

        pq.emplace(grid[0][0],0,0);
        vis[0][0]=1;
        while(!pq.empty()){
            auto[t,r,c]=pq.top();
            pq.pop();
            if(r==m-1&&c==n-1)return t;
            for(int dir=0;dir<4;dir++){
                int nr=r+moves[dir];
                int nc=c+moves[dir+1];
                if(nr<0||nc<0||nr>=m||nc>=n||vis[nr][nc])
                    continue;
                pq.emplace(max(t,grid[nr][nc]),nr,nc);
                vis[nr][nc]=1;
            }
        }
        return INT_MAX;
    }
};