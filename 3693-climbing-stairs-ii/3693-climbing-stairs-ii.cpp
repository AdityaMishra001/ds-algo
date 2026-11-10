class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        int costPrev1 = 0, costPrev2 = 1e5, costPrev3 = 1e5;
        for (int step = 1; step <= n; step++) {
            int currMinCost = cost[step-1]+min({1LL+costPrev1, 4LL+costPrev2, 9LL+costPrev3});
            // (i-1) cause 1 based indexing needed to be handled
            costPrev3 = costPrev2;
            costPrev2 = costPrev1;
            costPrev1 = currMinCost;
        }
        return costPrev1;
    }
};