class Solution {
    vector<vector<string>>ans;
    vector<string>board;
    vector<int>rightDiag,leftDiag,top;
    int n;
public:
    void solve(int row){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(rightDiag[row+col] || leftDiag[n-1+col-row] || top[col] )continue;

            board[row][col]='Q';
            rightDiag[row+col] = leftDiag[n-1+col-row] = top[col]=1;
            solve(row+1);
            board[row][col]='.';
            rightDiag[row+col] = leftDiag[n-1+col-row] = top[col]=0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear(),board.clear();
        this->n=n;
        rightDiag.assign(2*n,0),leftDiag.assign(2*n,0),top.assign(n,0);

        for(int i=0;i<n;i++){
            string row(n,'.');
            board.push_back(row);
        }

        solve(0);
        return ans;
    }
};