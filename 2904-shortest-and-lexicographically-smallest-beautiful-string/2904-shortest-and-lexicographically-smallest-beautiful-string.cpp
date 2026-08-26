class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        string ans="";
        int l=0;
        int ct=0;
        for(int r=0;r<n;r++){
            ct+=s[r]-'0';
            while(ct>k){
                ct-=(s[l]-'0');
                l++;
            }
            
            if(ct==k){
                while(s[l]=='0')l++;
                string curr=s.substr(l,r-l+1);
                if(ans=="" || ans.size()>curr.size() ||
                    (ans.size()==curr.size() && ans>curr)){
                    ans=curr;
                }
            }

        }
        return ans;
    }
};