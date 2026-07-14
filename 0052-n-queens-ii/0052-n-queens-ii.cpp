class Solution {
public:
    int solve(int colMask,int leftDigMask, int rightDigMask, int n){
        int mask= (1<<n)-1;

        if(colMask==mask)return 1;

        int ct=0;
        int available= (~(colMask|leftDigMask| rightDigMask)) & mask;
        while(available){
            int p=available& -available;//rightmostSetBit
            ct+= solve( colMask|p,(leftDigMask|p)>>1,(rightDigMask|p)<<1,n );
            available-=p;
        }
        return ct;

    }
    int totalNQueens(int n) {
        return solve(0,0,0,n);
    }
};