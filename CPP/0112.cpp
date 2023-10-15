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
    bool dfs(TreeNode* root,int targetSum){
        if(root==NULL){
            return false;
        }
        if(root->val==targetSum&&root->left==NULL&&root->right==NULL){
            return true;
        }
        
        if(dfs(root->left,targetSum-root->val)){
            return true;
        }
        if(dfs(root->right,targetSum-root->val)){
            return true;
        }
        
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if(root==NULL){
        //     return false;
        // }
        // if(root->val==targetSum){
        //     return true;
        // }
        return dfs(root,targetSum);
    }
};
