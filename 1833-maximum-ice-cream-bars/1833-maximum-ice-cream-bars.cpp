class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int max_ele=*max_element(costs.begin(),costs.end());

        vector<int>frequency(max_ele);//default /filled with zero's

        for(int i=0;i<n;i++){
            frequency[costs[i] -1]++;
        }

        int number_of_IceCreams=0;
        for(int i=0;i<max_ele;i++){
            int price=i+1;
            while(coins>=price && frequency[i]-- ){
                coins-=price;
                number_of_IceCreams++;
            }
        }
        return number_of_IceCreams;

    }
};