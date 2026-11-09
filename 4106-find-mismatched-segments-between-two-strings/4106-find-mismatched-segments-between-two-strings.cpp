class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n = s1.size();
        string d1 = "", d2 = "";
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                d1 += s1[i];
                d2 += s2[i];
            } else {
                if (d1.size() != 0) {
                    vector<string> temp;
                    temp.push_back(d1);
                    temp.push_back(d2);
                    ans.push_back(temp);
                    d1 = "", d2 = "";
                }
            }
        }
        if (d1.size() != 0) {
            vector<string> temp;
            temp.push_back(d1);
            temp.push_back(d2);
            ans.push_back(temp);
            d1 = "", d2 = "";
        }

        return ans;
    }
};