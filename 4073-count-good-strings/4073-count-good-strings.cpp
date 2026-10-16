class Solution {
public:
    int m=1e9+7;
    unordered_map<long long, pair<int,int>>memo;

    pair<long long, long long>f(long long n){
        if(n==0)return {0,1};

        if(memo.count(n))return memo[n];

        auto[a,b]=f(n/2);
        long long c= a*((2*b%m-a+m)%m)%m;
        long long d= (a*a%m+b*b%m)%m;
        if(n%2==0)return memo[n]={c,d};
        return memo[n]={d,(c+d)%m};
    }
    int countGoodStrings(long long n) {
        memo.clear();
        return 2*f(n).first%m;
    }
};