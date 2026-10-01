class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int >ans(n,0);
        int sign=(k>0)? 1: -1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=abs(k);j++){
                ans[i]+=code[(0LL+n+i+sign*j)%n];
            }
        }

        return ans;
        
    }
};