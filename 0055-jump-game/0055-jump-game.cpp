class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(furthest<i)return 0;
            furthest=max(furthest,i+nums[i]);
            if(furthest>=n-1)
                return 1;
        }
        return 0;
    }
};