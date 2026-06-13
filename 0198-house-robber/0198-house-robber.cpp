class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==1)
            return nums[0];
        
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        int profit;
        for(int i=2;i<n;i++){
            profit=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=profit;
        }
        return prev1;

    }
};