class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))return 0;
        if(is_sorted(nums.rbegin(),nums.rend()))return 1;
        int n=nums.size();
        if(n==2)return 1;

        bool increasing=nums[0]>nums[n-1];
        bool drop=false;
        int dropId=-1;
        if(increasing==1){
            for(int i=1;i<n;i++){
                if(nums[i-1]>nums[i]){
                    if(drop)return -1;
                    drop=true;
                    dropId=i;
                }
            }
        }else{
            for(int i=1;i<n;i++){
                if(nums[i-1]<nums[i]){
                    if(drop)return -1;
                    drop=true;
                    dropId=i;
                }
            }
        }

        if(increasing){
            //pushing 0 to start
            int left_cost=dropId;
            //reverse
            dropId=n-1-dropId;
            int right_cost=3+dropId;
            return min(left_cost,right_cost);
        }else{
            int left_cost=dropId+1;
            int right_cost=n-dropId+1;
            return min(left_cost,right_cost);
        }
        return -1;
    }
};