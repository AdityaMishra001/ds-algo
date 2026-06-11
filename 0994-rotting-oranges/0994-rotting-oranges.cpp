class Solution {
public:
    vector<int>dir={1,0,-1,0,1};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int freshCount=0;
        queue<pair<int,int>>q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    freshCount++;    
            }
        }
        if(freshCount==0)return 0;
        int timer=0;
        int newRotted=0;
        while(!q.empty()){
            int n=q.size();
            bool workDoneThisLevel=0;
            while(n--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int xnew=x+dir[i];
                    int ynew=y+dir[i+1];
                    if(xnew<0 || ynew<0 || xnew>=rows || ynew>=cols|| grid[xnew][ynew]!=1 )
                    continue;

                    grid[xnew][ynew]=-1;
                    q.push({xnew,ynew});
                    newRotted++;
                    workDoneThisLevel=1;
                }
            }
            if(workDoneThisLevel)
            timer++;
        }
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         if(grid[i][j]==1)
        //             return -1;
        //     }
        // }
        
        return (freshCount==newRotted)? timer: -1;
    }
};