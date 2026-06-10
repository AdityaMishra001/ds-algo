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
    void dfs(vector<TreeNode*>&inorder,TreeNode* root){
        if(!root)
            return;
        dfs(inorder,root->left);
        inorder.push_back(root);
        dfs(inorder,root->right);    
    }
    TreeNode* construct(vector<TreeNode*>&inorder,int l,int r){
        if(l>r)
            return nullptr;
        int mid=l+(r-l)/2;
        
        TreeNode* curr=inorder[mid];

        curr->left= construct(inorder,l,mid-1) ;
        curr->right= construct(inorder,mid+1,r) ;  
        return curr;    
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root )
            return root;
        vector<TreeNode*>inorder;
        dfs(inorder,root);
        return construct(inorder,0,inorder.size()-1);
        
    }
    
};













// class Solution {
// public:
//     vector<TreeNode*>inorder;
//     void dfs(TreeNode* root){
//         if(!root)
//             return;
//         dfs(root->left);
//         inorder.push_back(root);    
//     }
//     TreeNode* construct(vector<TreeNode*>inorder,int l,int r){
//         if(l>r)
//             return nullptr;
//         int mid=l+(r-l)/2;
        
//         TreeNode* curr=inorder[mid];

//         if(isValid(curr)){
//             return curr;
//         }
//         curr->left= construct(inorder,l,mid-1) ;
//         curr->right= construct(inorder,mid+1,r) ;  
//         return curr;    
//     }
//     TreeNode* balanceBST(TreeNode* root) {
//         if(!root || isValid(root))
//             return root;
//         inorder.clear();
//         return construct(inorder,0,inorder.size()-1);
        
//     }
//      bool check(TreeNode* root,long mn,long mx){
//         if(!root)
//             return 1;

//         if(mn<root->val && root->val<mx)
//         return check(root->left,mn,root->val) && check(root->right,root->val,mx); 
//         else
//         return 0;   
//     }
//     bool isValid(TreeNode* root) {
//         if(!root || (!root->left && !root->right))
//             return 1;
//         return check(root,LONG_MIN,LONG_MAX);
//     }
// };