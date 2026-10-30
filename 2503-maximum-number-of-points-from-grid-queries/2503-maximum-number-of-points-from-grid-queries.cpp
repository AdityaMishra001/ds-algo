class Solution {
    static inline vector<int>moves={-1,0,1,0,-1};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k=queries.size();
        int m=grid.size();
        int n=grid[0].size();

        vector<int>ans(k,0);
        vector<pair<int,int>>sortedQs;
        for(int i=0;i<k;i++)
            sortedQs.push_back({queries[i],i});
        sort(sortedQs.begin(),sortedQs.end());


        //{cellVal,r,c}
        using T=tuple<int,int,int>;
        priority_queue< T, vector<T>,greater<T>>pq;
        pq.push({grid[0][0],0,0});

        vector<vector<bool>>vis(m+1,vector<bool>(n+1,0));
        vis[0][0]=1;

        int points=0;
        for(auto &[limit,id]:sortedQs){
            while(!pq.empty() && get<0>(pq.top())<limit){
                auto[cellVal,r,c]=pq.top();
                pq.pop();
                points++;
                for(int dir=0;dir<4;dir++){
                    int nr=r+moves[dir];
                    int nc=c+moves[dir+1];
                    if(nr<0||nc<0||nr>=m||nc>=n||vis[nr][nc])
                        continue;
                    vis[nr][nc]=1;
                    pq.push({grid[nr][nc],nr,nc});
                }
            }

            ans[id]=points;
        }
        
        
        return ans;
    }
};