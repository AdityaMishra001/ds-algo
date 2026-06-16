class Solution {
public:
    void solve( vector<vector<string>>&ans,vector<string>&board,vector<bool>&AttackFromTop,vector<bool>&AttackFromTopl,vector<bool>&AttackFromTopr,int row,int n){
        if(row==n){
            //if all rows 0 to n-1 are filled now at index n save answer
            ans.push_back(board);
            return;
        }

        // at current row search for suitable col
        for(int col=0;col<n;col++){

            //if not possible continue;
            if(AttackFromTop[col] || AttackFromTopl[n-1+row-col] || AttackFromTopr[row+col])continue;
            
            //place the queen at possible place
            board[row][col]='Q';
            AttackFromTop[col]=1;
            AttackFromTopl[row-col+n-1]=1;
            AttackFromTopr[row+col]=1;

            solve(ans,board,AttackFromTop,AttackFromTopl,AttackFromTopr,row+1,n);

            //remove queen
            board[row][col]='.';
            AttackFromTop[col]=0;
            AttackFromTopl[row-col+n-1]=0;
            AttackFromTopr[row+col]=0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board;
        for(int i=0;i<n;i++){
            string row(n,'.');
            board.push_back(row);
        }
        vector<bool> AttackFromTop(n),AttackFromTopl(2*n-1),AttackFromTopr(2*n-1);
        solve(ans,board,AttackFromTop,AttackFromTopl,AttackFromTopr,0,n);
        //cal helper to generate the ans
        //call for 0th row 
        return ans;
    }
};