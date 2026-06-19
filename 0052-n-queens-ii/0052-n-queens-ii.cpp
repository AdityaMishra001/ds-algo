class Solution {
public:
    
    void solve(vector<bool>&ColAttk,vector<bool>&lDigAttk,vector<bool>&rDigAttk,int row, int n,int &ct){
        if(row==n){
            ct++;
            return;
        }

        

        for(int col=0;col<n;col++){
            if(ColAttk[col] || lDigAttk[n-1+col-row] || rDigAttk[row+col])continue;
            ColAttk[col]=1;
            lDigAttk[n-1+col-row]=1;
            rDigAttk[row+col]=1;

            solve(ColAttk,lDigAttk,rDigAttk,row+1,n,ct);
            
            ColAttk[col]=0;
            lDigAttk[n-1+col-row]=0;
            rDigAttk[row+col]=0;

        }
    }
    
    int totalNQueens(int n) {
        int ct=0;
        vector<bool>ColAttk(n),lDigAttk(2*n-1),rDigAttk(2*n-1);

        solve(ColAttk,lDigAttk,rDigAttk,0,n,ct);
        return ct;
    }
};