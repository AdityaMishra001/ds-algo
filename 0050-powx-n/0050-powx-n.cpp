class Solution {
public:
    double myPow(double x, long long n){
        if(x==1||n==1)return x;
        if(n==0)return 1;
        double half=myPow(x,n/2);
        if(n%2==0)return half*half;
        return half*half*x;
    }
    double myPow(double x, int n) {
        if(n<0)
            return 1/myPow(x,1LL*n);
        return myPow(x,1LL*n);
    }
};