class Solution {
public:
    bool check(vector<int>&nums,int k, int capacity){
        int count=1;
        int currSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>capacity)return 0;

            if(currSum+nums[i] <=capacity){
                currSum+=nums[i];
            }else{
                currSum=nums[i];
                count++;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low= *max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0);
        long long ans;

        while(low<=high){
            long long mid= low + ((high -low)>>1);

            if(check(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};