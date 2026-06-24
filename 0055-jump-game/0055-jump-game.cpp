class Solution {
    int n;
    vector<int>dp;
public:
    // bool helper(vector<int>&nums,int i){
    //     if(i>=n-1){
    //         return 1;
    //     }
    //     if(dp[i]!=-1){
    //         return dp[i];
    //     }
    //     if(nums[i]==0 && i<n-1){
    //         return 0;
    //     }
    //     bool isPossible=0;
    //     for(int j=1;j<=nums[i];j++){
    //         if(i+j<n && helper(nums,i+j))
    //             isPossible|= 1;
    //     }
    //     return dp[i]=isPossible;
    // }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,-1);
        dp[n-1]=1;

        for(int i=n-2;i>=0;i--){
            dp[i]=false;
            for(int j=1;j<=nums[i];j++){
                if(i+j>=n-1 || dp[i+j]){
                    dp[i]=1;
                    break;
                }
            }
        }


        return dp[0];
    }
};