class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string curr;
        bool inBlock = false;
        for (const string& s : source) {
            int n = s.size();
            for (int i = 0; i < n; i++) {
                if (inBlock) {
                    if (i + 1 < n && s[i] == '*' && s[i + 1] == '/') {
                        i++;
                        inBlock = false;
                    }
                } else {
                    if (i + 1 < n && s[i] == '/' && s[i + 1] == '/') {
                        break;
                    }
                    else if (i + 1 < n && s[i] == '/' && s[i + 1] == '*') {
                        i++;
                        inBlock = true;
                    }
                    else{
                        curr+=s[i];
                    }
                }
            }
            if(!inBlock && !curr.empty()){
                ans.push_back(curr);
                curr="";
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<string> removeComments(vector<string>& source) {
//         vector<string> ans;
//         bool openComment = false;
//         int id = -1;
//         string open = "";
//         bool same = 1;
//         for (int j = 0; j < source.size(); j++) {
//             string& s = source[j];
//             string curr = "";
//             int n = s.size();
//             for (int i = 0; i < n; i++) {
//                 if (i + 1 < n && s[i] == '/' && s[i + 1] == '/') {
//                     break;
//                 }
//                 if (i + 1 < n && s[i] == '/' && s[i + 1] == '*') {
//                     i++;
//                     openComment = true;
//                     open = curr;
//                     id = j;
//                     same = 0;
//                 }
//                 if (openComment) {
//                     if (i + 1 < n && s[i] == '*' && s[i + 1] == '/') {
//                         i++;
//                         openComment = false;
//                         if (j == id) {
//                             same = 1;
//                             curr = open + curr;
//                         }
//                         open = "";
//                         id = -1;
//                     } else {
//                         continue;
//                     }
//                 } else {
//                     curr += s[i];
//                 }
//             }

//             if (!same && !openComment && open.size() > 0) {
//                 open += curr;
//                 if (open.size() > 0) {
//                     ans.push_back(open);
//                 }
//             } else if (curr.size() > 0) {
//                 ans.push_back(curr);
//             }
//         }

//         return ans;
//     }
// };