class Solution {
public:
    static inline unordered_set<int>primes;
    static inline bool generated=false;     
    static bool is_prime(int num){
        if(num<=1)return false;
        for(int i=2;i<=num/i;i++){
            if(num%i==0)return 0;
        }
        return 1;
    }
    static void generate(){
        int i=2;
        while(primes.size()<20){
            if(is_prime(i))primes.insert(i);
            i++;
        }
        generated=true;
    }
    int countPrimeSetBits(int left, int right) {
        if(!generated)generate();
        int ct=0;
        for(int i=left;i<=right;i++){
            if(primes.find(__builtin_popcount(i))!=primes.end()){
                ct++;
            }
        }
        return ct;
    }
};