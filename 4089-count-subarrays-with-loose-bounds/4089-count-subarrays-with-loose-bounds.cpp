class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ct=0;
        int l=0,n=nums.size();
        for(int r=0;r<n;r++){
            if(minK<=nums[r]&&nums[r]<=maxK)ct+=r-l+1;
            else l=r+1;
        }
        return ct;
    }
};