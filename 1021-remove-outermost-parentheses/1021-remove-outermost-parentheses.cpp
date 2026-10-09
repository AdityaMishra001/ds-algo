class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string ans;
        for(char c:s){
            if(c=='('){
                if(balance){
                    ans+='(';
                }
                balance++;
            }else{
                balance--;
                if(balance){
                    ans+=')';
                }
            }
        }
        return ans;
    }
};