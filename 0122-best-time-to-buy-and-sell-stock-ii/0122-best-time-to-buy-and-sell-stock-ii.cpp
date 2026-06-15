using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    int helper(vi& prices, int day, int state, vvi&memo) {
        if (day == prices.size())
            return 0;
        if(memo[day][state] != -1)
            return memo[day][state];
        int profit = 0;
        if (state == 0) {
            int buy = -prices[day] + helper(prices, day + 1, 1, memo);
            int dontBuy = helper(prices, day + 1, 0, memo);
            profit = max(buy, dontBuy);
        } else {
            int sell = prices[day] + helper(prices, day + 1, 0, memo);
            int dontSell = helper(prices, day + 1, 1, memo);
            profit = max(sell, dontSell);
        }
        return memo[day][state] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        vvi memo(prices.size() + 5, vi(2, -1));
        return helper(prices, 0, 0, memo);
    }
};