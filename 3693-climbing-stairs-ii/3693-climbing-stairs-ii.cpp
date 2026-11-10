class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        int minCost = 1e5;
        int prev1 = 0, prev2 = 1e5, prev3 = 1e5;
        for (int i = 1; i <= n; i++) {
            minCost = cost[i-1]+min({1LL+prev1, 4LL+prev2, 9LL+prev3});
            // (i-1) cause 1 based indexing needed to be handled
            prev3 = prev2;
            prev2 = prev1;
            prev1 = minCost;
        }
        return prev1;
    }
};
// class Solution {
// public:
//     int helper(vector<int>&dp,vector<int>&cost,int n,int i){
//         if(i==n)return 0;
//         if(i>n)return INT_MAX;
//         if(dp[i]!=-1)return dp[i];

//         long long minCost=INT_MAX;
//         for(int j=i+1;j<=i+3 && j<=n;j++){
//             long long currCost=helper(dp,cost,n,j);
//             if(currCost==INT_MAX)continue;
//             currCost=cost[j-1]+1L*(j-i)*(j-i);
//             minCost=min(currCost,minCost);
//         }

//         return dp[i]=minCost;
//     }
//     int climbStairs(int n, vector<int>& costs) {
//         vector<int>dp(n+1,-1);
//         return helper(dp,costs,n,0);
//     }
// };