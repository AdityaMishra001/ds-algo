class Solution {
public:
    //approach 1
    //brute force
    //from every cell search for min distance 0
    // m*n celss *( search => m*n) ~O((m*n)^2)

    //approach 2
    //initialize ans with -1
    //now mark all zeros
    //now for each zero
    //update all cells connected to 1(if neighbour is !-1 avoid this path)
    //now neighbour of 2 are marked 2;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();

        vector<vector<int>>ans(rows,vector<int>(cols,-1));

        vector<vector<int>>dir={{1,0},{0,-1},{-1,0},{0,1}};
        queue<pair<int,int>>q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto[x,y]=q.front();
                q.pop();

                for(int v=0;v<4;v++){
                    int xnew=x+dir[v][0];
                    int ynew=y+dir[v][1];

                    if(xnew<0 || ynew<0 || xnew>=rows || ynew>=cols ||
                    ans[xnew][ynew]!=-1){
                        continue;
                    }
                    ans[xnew][ynew]=ans[x][y]+1;
                    q.push({xnew,ynew});
                }
            }
        }
        return ans;
    }
};