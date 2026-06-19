class Solution {
    int MOD=1e9+7;
public:
    // int modPow(long long  base,long long power){
    //     if(power==1)
    //         return base;
    //     if(power==0)
    //         return 1;    
    //     long long val,half;

    //     half= modPow(base,power/2);
    //     val=(half*half)%MOD;

    //     if(power%2==1)
    //         val=( val * base)%MOD;
        
    //     return int(val);
    // }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool>visited(n+1);
        queue<int>q;
        q.push(1);
        visited[1]=true;

        int ans=1;
        bool first=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();

                for(int child:adj[curr]){
                    if(!visited[child]){
                        q.push(child);
                        visited[child]=true;
                    }
                }
            }
            if(!q.empty()){
                if(first)
                    first=0;
                else
                    ans=(2LL*ans)%MOD;
            }
        }

        return ans;
    }
};