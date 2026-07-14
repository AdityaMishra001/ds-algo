class Solution {
    int n;
    vector<string>validPar;
    string curr;
    void generate(int l,int r,string &curr){
        if(l+r==2*n){
            validPar.push_back(curr);
            return;
        }
        
        //add left;
        if(l<n){
            curr.push_back('(');
            generate(l+1,r,curr);
            curr.pop_back();
        }
        
        //add right
        if(l>r && l+r<2*n){
            curr.push_back(')');
            generate(l,r+1,curr);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n=n;
        validPar.clear();
        curr="";
        generate(0,0,curr);
        return validPar;
    }
};