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
    void dfs(TreeNode* root,int targetSum,vector<int>&tmp,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        tmp.push_back(root->val);
        if(root->val==targetSum&&root->left==NULL&&root->right==NULL){
            ans.push_back(tmp);
        }
        dfs(root->left,targetSum-root->val,tmp,ans);
        dfs(root->right,targetSum-root->val,tmp,ans);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>tmp;
        dfs(root,targetSum,tmp,ans);
        return ans;
    }
};
