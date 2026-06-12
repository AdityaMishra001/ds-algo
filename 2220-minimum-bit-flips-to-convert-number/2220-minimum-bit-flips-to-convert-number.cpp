class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ct=0;
        int mask=1;
        for(int i=0;i<32;i++){
            if((start&mask) ^ (goal&mask) )ct++;
            mask<<=1;
        }
        return ct;
    }
};