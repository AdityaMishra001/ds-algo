class Solution {
public:

    int beautySum(string s) {
        int sum=0;
        int n=s.size();
        for(int l=0;l<n;l++){
            vector<int>freq(26,0);
            int maxf=0;
            for(int r=l;r<n;r++){
                freq[s[r]-'a']++;
                maxf=max(maxf,freq[s[r]-'a']);
                int minf=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>0)minf=min(minf,freq[k]);
                }
                sum+=maxf-minf;
            }
        }
        return sum;
    }
};