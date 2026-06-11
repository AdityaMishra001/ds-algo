class Solution {
public:
    //brute force 
    //create 
    //4 vector's -> o's and 1's in rows and similarly do same for cols
    
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        vector<vector<int>>diff(rows,vector<int>(cols,-1));

        // vector<vector<int>>dir={{1,0},{0,-1},{-1,0},{0,1}};
        // queue<pair<int,int>>q;

        vector<int>onesRows(rows),onesCols(cols);
        for(int i=0;i<rows;i++){
            int currRowOnes=0;
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1)currRowOnes++;
            }
            onesRows[i]=currRowOnes;
        }
        for(int i=0;i<cols;i++){
            int currColOnes=0;
            for(int j=0;j<rows;j++){
                if(grid[j][i]==1)currColOnes++;
            }
            onesCols[i]=currColOnes;
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // diff[i][j]=onesRows[i]+onesCols[j]-(rows-onesRows[i])-(cols-onesCols[j]);
                diff[i][j]=2*onesRows[i]+2*onesCols[j]-rows-cols;
            }
        }
        return diff;
    }
};