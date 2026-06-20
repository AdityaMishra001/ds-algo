class Solution {
public:
    void helper(vector<string>&all,string &curr,int i){
        if(i==curr.size()){
            all.push_back(curr);
            return;
        }

        curr[i]='1';
        helper(all,curr,i+1);
        
        if(i==0 || curr[i-1]!='0'){
            curr[i]='0';
            helper(all,curr,i+1);
        }
       

    }
    vector<string> validStrings(int n) {
        vector<string>all;
        string curr(n,'0');
        

        helper(all,curr,0);
        return all;
    }
};