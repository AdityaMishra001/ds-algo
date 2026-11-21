class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(),k=3;
        int minDiff=INT_MAX;
        if (n<= k + 1)
            return 0;
        sort(nums.begin(),nums.end());
        for(int r=n-1,l=k;l>=0;r--,l--){
            minDiff=min(minDiff,nums[r]-nums[l]);
        }
        return minDiff;
        
    }
};