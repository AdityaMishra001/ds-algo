class Solution {
public:
    int helper(vector<vector<int>>& dp,vector<int>& prices,int day,int state){
        if(day==prices.size()){
            return 0;
        }
        if(dp[state][day]!=-1){
            return dp[state][day];
        }

        int profit=0;
        if(state==0){
            int buy=-prices[day]+helper(dp,prices,day+1,1);
            int dontbuy=helper(dp,prices,day+1,0);
            profit=max(buy, dontbuy);
        }else{
            int sell= prices[day]+helper(dp,prices,day+1,0);
            int dontsell=helper(dp,prices,day+1,1);
            profit=max(sell,dontsell);
        }
        return dp[state][day]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(2,vector<int>(n,-1));
        return helper(dp,prices,0,0);
        
    }
};



// class Solution {
// public:
//     void helper(vector<int>&prices,int i,int prev,int currProfit,int& maxProfit){
//         if(i==prices.size()){
//             return;
//         }
//         maxProfit=max(maxProfit,currProfit);

//         //skip
//         helper(prices,i+1,prev,currProfit,maxProfit);

//         //sell & buy
//         helper(prices,i+1,prices[i],currProfit+prices[i]-prev,maxProfit);


//     }
//     int maxProfit(vector<int>& prices) {
//         int maxProfit=0;
//         helper(prices,0,prices[0],0,maxProfit);
//         return maxProfit;
//     }
// };