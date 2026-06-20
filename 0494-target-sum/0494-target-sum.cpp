class Solution {
public:
    int helper(vector<int>&nums,int pTarget,int i){
        
        if(i==nums.size() )
            return pTarget==0;

        return helper(nums,pTarget-nums[i],i+1)+helper(nums,pTarget,i+1);    

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // positive part and neg part = target

        // p-n=targ
        // p+n=total
        // 2p=targ+total
        // p=(targ+total)/2

        int total=accumulate(nums.begin(),nums.end(),0);

        if(abs(target)>total)
            return 0;
        int p=target+total;
        if(p%2==1)
            return 0;
        p/=2;
        return helper(nums,p,0);
    }
};