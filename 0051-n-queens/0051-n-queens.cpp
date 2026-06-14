class Solution {
public:
    
    void solve(vector<vector<string>> &ans,vector<vector<char>> &board,vector<bool>&ColAttk,vector<bool>&lDigAttk,vector<bool>&rDigAttk,int row, int n){
        if(row==n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string curr_row(board[i].begin(),board[i].end());
                temp.push_back(curr_row);
            }
            ans.push_back(temp);
            return;
        }

        

        for(int col=0;col<n;col++){
            if(ColAttk[col] || lDigAttk[n-1+col-row] || rDigAttk[row+col])continue;
            ColAttk[col]=1;
            lDigAttk[n-1+col-row]=1;
            rDigAttk[row+col]=1;
            board[row][col]='Q';

            solve(ans,board,ColAttk,lDigAttk,rDigAttk,row+1,n);
            
            ColAttk[col]=0;
            lDigAttk[n-1+col-row]=0;
            rDigAttk[row+col]=0;
            board[row][col]='.';

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<bool>ColAttk(n),lDigAttk(2*n-1),rDigAttk(2*n-1);

        solve(ans,board,ColAttk,lDigAttk,rDigAttk,0,n);
        return ans;
    }
};