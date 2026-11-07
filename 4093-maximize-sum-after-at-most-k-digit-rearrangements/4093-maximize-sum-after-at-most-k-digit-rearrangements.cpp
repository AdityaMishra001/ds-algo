class Solution {
public:
    long long increase(int &num){
        string x=to_string(num);
        sort(x.rbegin(),x.rend());
        long long maxVal=stol(x);
        return maxVal-num;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        long long maxSum=accumulate(nums.begin(),nums.end(),0LL);
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(increase(nums[i]));
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty())maxSum+=pq.top(),pq.pop();
        return maxSum;
    }
};