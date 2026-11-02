class Solution {
public:
    int moves_req(vector<int>&nums,int median){
        int moves=0;
        int n=nums.size();
        for(int&num:nums)moves+=abs(num-median);
        return moves;
    }
    int partition(vector<int>&nums,int low,int high){
        // int pivotId=low+ rand()%(high-low+1);
        int pivot_val=nums[high];
        // swap(nums[pivotId],nums[high]);
        int i=low-1;
        for(int j=low;j<high;j++){
            if(nums[j]<=pivot_val){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[++i],nums[high]);
        return i;
    }
    int find_median(vector<int>&nums,int low,int high,int k){
        if(low>high)return -1;
        int pivot_id=partition(nums,low,high);

        if(pivot_id==k)return pivot_id;
        else if(pivot_id>k){
            return find_median(nums,low,pivot_id-1,k);
        }else{
            return find_median(nums,pivot_id+1,high,k);
        }
    }
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int median_id=find_median(nums,0,n-1,n/2);
        return moves_req(nums,nums[median_id]);
    }
};