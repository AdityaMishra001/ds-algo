class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ct=0;

        int m=grid.size();
        int n=grid[0].size();
        vector<bool>row(m,0),col(n,0);
        for(int i=0;i<m;i++){
            int servers=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)servers++;
            }
            row[i]=(servers>1);
        }
        for(int j=0;j<n;j++){
            int servers=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]!=0)servers++;
            }
            col[j]=(servers>1);
               
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0
                &&(row[i]||col[j])){
                    ct++;
                }
            }
        }



        return ct;

    }
};