class Solution {
public:
void dfs(vector<vector<int>>&isConnected,vector<bool>&visited,int node){
     visited[node]=1;
     for(int j=0;j<isConnected.size();j++){
        if(isConnected[node][j]==1 && !visited[j])
        dfs(isConnected,visited,j);
     }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        int provinces=0;
        vector<bool>visited(v);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                provinces++;
            dfs(isConnected,visited,i);
            }
        }
        return provinces;
    }
};