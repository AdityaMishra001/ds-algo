class Solution {
public:
    // void dfs(vector<vector<int>>&grid,int x,int y){
    //     if(x<0 || y<0 || x>grid.size()-1 || y>grid[0].size()-1 || grid[x][y]==0)
    //         return;
    //     grid[x][y]=0;
        
    //     dfs(grid,x+1,y);    
    //     dfs(grid,x,y+1);
    //     dfs(grid,x-1,y);
    //     dfs(grid,x,y-1);
    // }
    using pii=pair<int,int>;
    int numEnclaves(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<pii>q;
        for(int i=0;i<rows;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0]=0;
            }
            if(grid[i][cols-1]==1){
                q.push({i,cols-1});
                grid[i][cols-1]=0;
            }
        }
        for(int j=0;j<cols;j++){
            if(grid[0][j]==1){
                q.push({0,j});
                grid[0][j]=0;
            }
            if(grid[rows-1][j]==1){
                q.push({rows-1,j});
                grid[rows-1][j]=0;
            }
        }

        

        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(i==0 || j==0 || i==rows-1 || j==cols-1){
        //             if(grid[i][j]==1){
        //                 q.push({i,j});
        //                 grid[i][j]=0;
        //             }
        //         }
        //     }
        // }
        vector<int>dir={-1,0,1,0,-1};
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto[x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int xnew=x+dir[i];
                    int ynew=y+dir[i+1];
                    if(xnew<0 || ynew<0 ||xnew>rows-1 ||ynew>=cols-1 || grid[xnew][ynew]==0)
                        continue;

                    q.push({xnew,ynew});
                    grid[xnew][ynew]=0;
                }
            }
        }

        int ct=0;
        for(int i=1;i<rows-1;i++){
            for(int j=1;j<cols-1;j++){
                if(grid[i][j]==1){
                    ct++;
                }
            }
        }
        return ct;
    }
};