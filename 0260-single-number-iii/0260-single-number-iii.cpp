class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0,a=0,b=0;
        for(int num:nums){
            xorr^=num;
        }
        int mask= xorr & int( -1LL* xorr);

        
        for(int num:nums){
            if(num&mask){
                a^=num;
            }else{
                b^=num;
            }
        }
        return{a,b};
    }
};