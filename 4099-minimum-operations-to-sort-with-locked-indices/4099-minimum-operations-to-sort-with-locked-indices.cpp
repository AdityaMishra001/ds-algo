class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size(),operations=0;
        for(int i=0;i<n-1;i++){
            bool sorted=true;
            for(int j=0;j<n-1-i;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]),sorted=false,operations++;
                    if(locked[j])locked[j]=0,k--,operations++;
                    if(locked[j+1])locked[j+1]=0,k--,operations++;
                    if(k<0)return -1;
                }
            }
            if(sorted)break;
        }
        return operations;
    }
};