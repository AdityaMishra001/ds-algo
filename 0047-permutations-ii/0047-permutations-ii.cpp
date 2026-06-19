class Solution {
public:
    //approach using visited array

    // void helper(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,vector<bool>&visited){
    //     if(temp.size()==nums.size()){
    //         ans.push_back(temp);
    //         return;
    //     }

    //     for(int i=0;i<nums.size();i++){
    //         if(visited[i])continue;
    //         if(i!=0 && nums[i-1]==nums[i] && !visited[i-1])
    //             continue;

    //         temp.push_back(nums[i]);
    //         visited[i]=1;
    //         helper(ans,temp,nums,visited);
    //         temp.pop_back();
    //         visited[i]=0;

    //     }

    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());

    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     vector<bool>visited(nums.size());

    //     helper(ans,temp,nums,visited);

    //     return ans;
    // }

    //Hash map based approach

    // void helper(vector<vector<int>>&ans,vector<int>&temp,unordered_map<int,int>&freq,int n){
    //     if(temp.size()==n){
    //         ans.push_back(temp);
    //     }

       
    //      for(auto& [num,ct]:freq){
    //         if(!ct)
    //             continue;

    //         temp.push_back(num);   
    //         freq[num]--;
    //         helper(ans,temp,freq,n);
    //         freq[num]++;
    //         temp.pop_back(); 
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
        
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     unordered_map<int,int>freq;
    //     for(int it:nums){
    //         freq[it]++;
    //     }

    //     helper(ans,temp,freq,nums.size());
    //     return ans;
    // } 

    //Brute force Using sets(all purmutations) then ->vector(only unque values)

    //using swaps and using non used values at current level

        //                   1    1   2
        //               /             \ 
        //           1   1   2       2   1   1
        //           _       _       _       _ --> emiting index 1 as already seen before
        //       /  
        //       1 1 2    1 2 1   2 1 1
        //           |        |       |   
        //       1 1 2    1 2 1   2 1 1    

    void helper(vector<vector<int>>&ans,vector<int>&nums,int index){
        if(index==nums.size()){
            ans.push_back(nums);
        }

        unordered_set<int>seen;

        for(int i=index;i<nums.size();i++){
            if(seen.find(nums[i])!=seen.end())
                continue;

            seen.insert(nums[i]);
            swap(nums[i],nums[index]);
            helper(ans,nums,index+1);
            swap(nums[i],nums[index]);    
        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(ans,nums,0);
        return ans;
    }
};