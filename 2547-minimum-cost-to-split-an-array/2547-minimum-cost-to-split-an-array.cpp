class Solution {
    int n;
    vector<int>dp;
public:    
    int solve(vector<int>& nums, int k,int i){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];

        vector<int>freq(1001,0);
        
        int ans=INT_MAX;
        int sizeOfTrimmed=0;

        for(int j=i;j<n;j++){
            int x=nums[j];
            freq[x]++;

            if(freq[x]==2){
                sizeOfTrimmed+=2;
            }else if(freq[x]>2){
                sizeOfTrimmed++;
            }

            int cost=k+ sizeOfTrimmed;

            ans=min(ans,cost+solve(nums,k,j+1));
        }
        return dp[i]=ans;
    }
    int minCost(vector<int>& nums, int k) {
        n=nums.size();
        dp.assign(n,-1);

        return solve(nums,k,0);

    }
};





// //1,2,1,2,1,3,3  k=2
//     vector<vector<int>>left;//in left
//     vector<vector<int>>right;//curr+right

//     int minCost(vector<int>& nums, int k) {
//         int n=nums.size();
//         // left.resize(n,vector<int>(1000,0));
//         // right.resize(n,vector<int>(1000,0));

//         // for(int i=1;i<n;i++){
//         //     left[i]=left[i-1]+nums[i];
//         // }
//         // int low=1,high=n-1;

//         // while(low<=high){
//         //     int mid= low+(high-low)/2;

//         //     int lefHalfCost= k+
//         // }

//         [1,2,1,2,1]
//         1.   2,1,2,1]. 

//         freq( 
//         left->right 
//         in left check 
//             if currfreq==1 uniqueLeft--
//             if currFreq==0 unique left++;
//         in right check 
//             if curr freq==1 uniqueRight-- 
//             else if curr freq==2 uniqueRight++

//          ptr(2 to n)
//         size of left=> ptr-0=ptr and 
//             cost= k+ (trimed size)
//                         |
//                         | -> total- unique
//                         | -> ptr -uniqueLeft
//         size of right=> n-1 -ptr +1 and
//             cost= k+ (trimed size)
//                         |
//                         | -> total- unique
//                         | -> (n-1 -ptr +1 ) -uniqueRight  
//         update minCost=min(minCost,costLeft+costRight)  ;
//         at each step                           

//     }