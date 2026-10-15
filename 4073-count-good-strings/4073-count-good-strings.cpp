class Solution {
public:
    int m=1e9+7;
    pair<long long, long long>f(long long n){
        if(n==0)return {0,1};
        auto[a,b]=f(n/2);
        long long c= a*((2*b%m-a+m)%m)%m;
        long long d= (a*a%m+b*b%m)%m;
        if(n%2==0)return {c,d};
        return {d,(c+d)%m};
    }
    int countGoodStrings(long long n) {
        
        return 2*f(n).first%m;
    }
};