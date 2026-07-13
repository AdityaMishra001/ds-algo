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
    int MaxPathSum;
public:
    int helper(TreeNode*root){
        if(!root)return 0;

        int sumOnLeft=max(0,helper(root->left));
        int sumOnRight=max(0,helper(root->right));
        int currPathSum=sumOnLeft+sumOnRight+root->val;
        MaxPathSum=max(MaxPathSum,currPathSum);
        
        return max(sumOnLeft,sumOnRight)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        MaxPathSum=INT_MIN;
        helper(root);
        return MaxPathSum;
    }
};