class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch>='a' && ch<='z'){
                res+=ch;
            }else{
                if(ch=='#'){
                    res+=res;
                }else if(ch=='%'){
                    reverse(res.begin(),res.end());
                }else if(ch=='*'){
                    //res=res.substr(0,res.size()-1);
                    if(res.size()!=0)
                        res.pop_back();
                }else{
                    cout<<"invalid char entered"<<endl;
                }
            }
        }
        return res;
    }
};