class Solution {
public:
    void helper(int idx,int n,vector<int>& nums,vector<int>& tmp,vector<vector<int>>& ans){
        if(idx==n){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[idx]);
        helper(idx+1,n,nums,tmp,ans);
        tmp.pop_back();
        helper(idx+1,n,nums,tmp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        int n=nums.size();
        helper(0,n,nums,tmp,ans);
        return ans;
    }
};
