class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();

        vector<vector<int>>dp(n,vector<int>(27,0));
        for(int start=0;start<n;start++){
            vector<int>freq(26,0);
            int dist=0;
            for(int k=start;k<n;k++){
                if(freq[s[k]-'a']==0)dist++;
                freq[s[k]-'a']++;
                dp[start][dist]++;
            }
        }
        
        int ct=0;
        
        //ct of :start,distincts;
        for(int i=0;i<n-1;i++){
            vector<int>freq(26,0);
            int dist=0;
            for(int j=i;j<n-1 && j+dist<n;j++){
                if(freq[s[j]-'a']==0)dist++;
                freq[s[j]-'a']++;
                ct+=dp[j+1][dist];
            }
        }

        return ct;
    }
};