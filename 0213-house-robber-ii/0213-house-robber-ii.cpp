class Solution {
public:
    int solve(vector<int>&nums,int start,int end){
        if(start==end)
            return nums[start];

        int prev2=nums[start];
        int prev1=max(nums[start],nums[start+1]);
        int profit;
        for(int i=start+2;i<=end;i++){
            profit=max(prev1,prev2+nums[i]);//ie  (~rob, rob)
            prev2=prev1;
            prev1=profit;
        }
        return prev1; //can also ret prev1 or profit
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(solve(nums,0,n-2),solve(nums,1,n-1));

    }
};