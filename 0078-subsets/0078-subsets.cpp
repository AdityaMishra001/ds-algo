class Solution {
    int n;
public:
    void helper(vector<vector<int>>&ans,vector<int>&path,vector<int>&nums,int i){
        if(i==n){
            ans.push_back(path);
            return;
        }

        //leave
        helper(ans,path,nums,i+1);

        //take
        path.push_back(nums[i]);
        helper(ans,path,nums,i+1);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>path;
        helper(ans,path,nums,0);
        return ans;
    }
};