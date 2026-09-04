class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
            return 0;
        vector<int>postMin(n,nums[n-1]);
        for(int i=n-2;i>=0;i--){
            postMin[i]=min(nums[i],postMin[i+1]);
        }
        int preMax=nums[0];

        for(int i=0;i<n;i++){
            long long score= preMax-postMin[i];
            if(score<=(long long)k)
                return i;
            preMax=max(preMax,nums[i]);     
        }

        return -1;
    }
};