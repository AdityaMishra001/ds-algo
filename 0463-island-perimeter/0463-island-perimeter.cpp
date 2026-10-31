class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        int m=grid.size(),n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    p+=4;
                    if(i>0 && grid[i-1][j]==1)
                        p--;
                    if(j>0 && grid[i][j-1]==1)
                        p--;
                    if(i<m-1 && grid[i+1][j]==1)
                        p--;
                    if(j<n-1 && grid[i][j+1]==1)
                        p--;
                }
            }
        }
        return p;
    }
};