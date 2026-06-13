class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int eXor=0;
        for(int num:nums){
            eXor^=num;
        }
        int mask;
        for(int i=0;i<32;i++){
            if(eXor & (1<<i)){
                mask=i;
                break;
            }
        }
        mask=(1<<mask);

        int Xor=0;
        eXor=0;
        for(int num:nums){
            if(num&mask){
                eXor^=num;
            }else{
                Xor^=num;
            }
        }
        return{Xor,eXor};
    }
};