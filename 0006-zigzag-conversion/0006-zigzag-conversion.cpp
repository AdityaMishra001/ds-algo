class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size(),i=0;
        if(numRows==1 || n<=numRows)return s;

        vector<string>v(numRows);
        while(i<n){
            //v
            for(int row=0;row<numRows && i<n;row++,i++){
                v[row]+=s[i];
            }
            //d
            for(int row=numRows-2;row>=1 && i<n; row--,i++){
                v[row]+=s[i];
            }

        }
        s="";
        for(i=0;i<numRows;i++){
            s.insert(s.end(),v[i].begin(),v[i].end());
        }
        return s;
    }
};