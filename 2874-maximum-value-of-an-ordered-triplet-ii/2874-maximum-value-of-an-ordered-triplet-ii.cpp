class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long max_prod=0,min_prod;
        long long max_diff=0,max_no=0;
        long long min_diff=0,min_no=0;

        //what if neg allowed??
        for(int i=0;i<n;i++){
            max_prod=max(max_prod,max_diff*nums[i]);
            max_prod=max(max_prod,min_diff*nums[i]);
            
            max_diff=max(max_diff,max_no-nums[i]);
            min_diff=min(min_diff,min_no-nums[i]);

            max_no=max(max_no,1LL*nums[i]);
            min_no=min(min_no,1LL*nums[i]);
        }
        return (max_prod<0) ? 0: max_prod;
    }
};