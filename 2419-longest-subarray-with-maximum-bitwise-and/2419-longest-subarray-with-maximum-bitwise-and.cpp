class Solution {
public:
    //solve for contiguous maxVal number maxLen window 
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxVal= *max_element(nums.begin(),nums.end());

        int left=0,right=0;
        int maxLen=0;
        for(int right=0;right<n;right++){
            if(nums[right]!=maxVal){
                left=right+1;
            }
            else{
                maxLen=max(maxLen,right-left+1);
            }
        }
        return maxLen;
    }
};