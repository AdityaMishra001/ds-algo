class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revGraph(n);

        vector<int>out_degree(n,0);
        vector<bool>safe(n,false);
        queue<int>q;

        for(int i=0;i<n;i++){
            out_degree[i]=graph[i].size();
            if(out_degree[i]==0){
                q.push(i);
                safe[i]=1;
            }

            for(int g:graph[i]){
                revGraph[g].push_back(i);
            }
        }
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int curr=q.front();
                q.pop();
                for(int prev:revGraph[curr]){
                    out_degree[prev]--;
                    if(!out_degree[prev]){
                        q.push(prev);
                        safe[prev]=1;
                    }
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe[i])ans.push_back(i);
        }
        return ans;
    }
};