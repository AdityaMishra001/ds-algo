
class Solution {
    static bool generated;
    static vector<int>fact;
        
        
public:
    string getPermutation(int n, int k) {
        if(!generated){
            fact.resize(10,1);
            //indexing 0 to n so all factorial are there

            for(int i=2;i<10;i++){
                fact[i]=fact[i-1]*i;
            }
            generated=1;
        }

        vector<int>values;
        for(int i=1;i<=n;i++){
            values.push_back(i);
        }

        k--;
        //indexing based

        

        string kthPer="";

        for(int i=n;i>=1;i--){
            int idx= k/fact[i-1];
            k%=fact[i-1];

            kthPer+= char('0'+values[idx]);
            values.erase(values.begin()+idx);
        }

        return kthPer;

    }
};
bool Solution:: generated=0;
vector<int> Solution::fact;