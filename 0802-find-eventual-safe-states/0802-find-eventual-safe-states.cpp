class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<bool>&safe,vector<bool>&visited,vector<bool>&pathVis){

        visited[node]=pathVis[node]=1;
        for(int neigh:graph[node]){
            if(!visited[neigh]){
                if(dfs(neigh,graph,safe,visited,pathVis))
                    return 1;//cycle
            }else if(pathVis[neigh]){
                return 1;//cycel
            }
        }
        pathVis[node]=0;//backtrack
        safe[node]=1;
        return false;//no cycle
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>safe(n),visited(n),pathVis(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,safe,visited,pathVis);
            }
        }

        vector<int>safe_nodes;
        for(int i=0;i<n;i++){
            if(safe[i])
            safe_nodes.push_back(i);
        }
        return safe_nodes;
    }
};