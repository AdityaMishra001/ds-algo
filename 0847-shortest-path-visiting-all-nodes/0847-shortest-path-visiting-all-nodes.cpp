class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<bool>>visited(n,vector<bool>(1<<n));
        int completeMask=(1<<n)-1;
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            q.push({(1<<i),i,0});
            visited[i][(1<<i)]=1;
        }
        while(!q.empty()){
            auto[currMask,currNode,dist]=q.front();
            q.pop();
            if(currMask==completeMask)
                return dist;
            int newMask;
            for(int neigh:graph[currNode]){
                newMask=currMask;
                newMask|=(1<<neigh);
                if(!visited[neigh][newMask]){
                    visited[neigh][newMask]=1;
                    q.push({newMask,neigh,dist+1});
                }
            }    
            
        }
        return -1;
    }
};