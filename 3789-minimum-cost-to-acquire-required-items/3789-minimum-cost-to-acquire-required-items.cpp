class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2>costBoth){
            long long totalCost=1LL*min(need1,need2)*costBoth;
            if(need1>need2){
                totalCost+= 1LL* (need1-need2)*min(cost1,costBoth);
            }else if(need1<need2){
                totalCost+= 1LL* (need2-need1)*min(cost2,costBoth);
            }
            return totalCost;

        }else{
            return 1LL*cost1*need1+1LL*cost2*need2;
        }
        return -1;
    }
};