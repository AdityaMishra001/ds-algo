class Solution {
public:
    int uniquePaths(int m, int n) {
        // int D=m-1;
        // int R=n-1;

        if(m<n)swap(m,n);
        int ways=1;
        //considering n to be min
        for(int i=1;i<n;i++){
            ways= int( 1LL*ways* (m-1+i) / i );
        }

        return ways;
    }
};