class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        //distincts in window i,j
        vector<vector<int>>distincts(n,vector<int>(n,0));
        for(int start=0;start<n;start++){
            vector<bool>seen(26,0);
            int dist=0;
            for(int end=start;end<n;end++){
                if(seen[s[end]-'a']==0)dist++;
                seen[s[end]-'a']=1;
                distincts[start][end]=dist;
            }
        }
        
        int ct=0;

        //partitions through j
        for(int j=0;j<n-1;j++){
            vector<int>l_freq(27,0),r_freq(27,0);
            for(int i=0;i<=j;i++)
                l_freq[distincts[i][j]]++;
            for(int k=j+1;k<n;k++)
                r_freq[distincts[j+1][k]]++;
            

            for(int f=0;f<=26;f++){
                ct+=1LL*l_freq[f]*r_freq[f];
            }
        }

        return ct;
    }
};