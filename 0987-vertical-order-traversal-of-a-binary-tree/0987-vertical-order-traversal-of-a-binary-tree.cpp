/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return{};

        map<int,map<int,multiset<int>>>map;
        int left=0,right=0;
        int height=0;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            height++;
            for(int i=0;i<n;i++){
                auto [curr, coordinates]=q.front();
                int horizontal=coordinates.first;
                int vertical=coordinates.second;
                left=min(left,horizontal);
                right=max(right,horizontal);
                q.pop();
                map[horizontal][vertical].insert(curr->val);
                if(curr->left){
                    q.push({curr->left,{horizontal-1,vertical+1}});
                }
                if(curr->right){
                    q.push({curr->right,{horizontal+1,vertical+1}});
                }
            }
        }

        //map<int,map<int,multiset<int>>>map;
        // vector<vector<int>>ans;
        // for(auto &x:map){
        //     vector<int>temp;
        //     for(auto &y:x.second){
        //         for(auto val:y.second){
        //             temp.push_back(val);
        //         }
        //     }
        //     ans.push_back(temp);
        // }

        vector<vector<int>>ans;
        for(auto &x:map){
            vector<int>temp;
            for(auto &y:x.second){
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }

        
        return ans;
    }
};