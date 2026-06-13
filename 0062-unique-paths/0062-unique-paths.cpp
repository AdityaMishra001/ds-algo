class Solution {
public:
    int uniquePaths(int m, int n) {
        int D=m-1;
        int R=n-1;

        if(R<D)swap(R,D);
        int ways=1;
        //considering D to be min
        for(int i=1;i<=D;i++){
            ways= int( 1LL*ways* (R+i) / i );
        }

        return ways;
    }
};