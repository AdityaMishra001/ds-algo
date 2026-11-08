class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        stringstream ss(s);
        string temp="";
        while(ss>>temp){
            words.push_back(temp);
        }
        reverse(words.begin(),words.end());
        s="";
        for(string &word:words)s+=word+' ';
        s.pop_back();
        return s;
    }
};