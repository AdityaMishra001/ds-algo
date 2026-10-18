class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.size();
        vector<int>indegree(n,0),degree(n,0);

        for(auto &e:edges){
            int u=e[0],v=e[1];

            degree[u]++,degree[v]++;
            
            //invalid case
            char a=colors[u],b=colors[v];
            if(a==b)return -1;

            if((a=='R'&&b=='B')||(a=='B'&&b=='W')||
                (a=='W'&&b=='R')){
                indegree[v]++;
            }else{
                indegree[u]++;
            }
        }

        int root=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                //second possible answer
                if(root!=-1)return -1;
                root=i;
            }else if(indegree[i]!=1){
                return -1;
            }
        }
        if(root!=-1 && degree[root]<=2)return root;
        return -1;
    }
};