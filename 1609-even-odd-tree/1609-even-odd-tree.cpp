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
    bool isEvenOddTree(TreeNode* root) {
        if(!root || (!root->left && !root->right && root->val%2==1))return 1;

        queue<TreeNode*>q;
        q.push(root);
        bool evenIndex=true;
        while(!q.empty()){
            int n=q.size();
            int temp=(evenIndex) ? INT_MIN : INT_MAX;
            while(n--){
                TreeNode* currNode=q.front();
                int currVal=currNode->val;
                q.pop();

                if(evenIndex){
                    if(currVal%2==0 || temp>=currVal)return 0;
                }else{
                    if(currVal%2==1 || temp<=currVal)return 0;
                }
                temp=currVal;
                
                if(currNode->left)q.push(currNode->left);
                if(currNode->right)q.push(currNode->right);
            }
            evenIndex=!evenIndex;
        }
        return true;
    }
};