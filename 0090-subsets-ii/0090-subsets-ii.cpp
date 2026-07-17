class Solution {
    int n;
public:
    void helper(vector<vector<int>>&ans,vector<int>&path,vector<int>&nums,int i,bool taken){
        if(i==n){
            ans.push_back(path);
            return;
        }

        if(i==0 || nums[i-1]!=nums[i] || nums[i-1]==nums[i] && taken){
            path.push_back(nums[i]);
            helper(ans,path,nums,i+1,1);
            path.pop_back();
        }
        helper(ans,path,nums,i+1,0);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>path;
        helper(ans,path,nums,0,0);
        return ans;
    }
};