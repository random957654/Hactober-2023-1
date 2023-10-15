class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int tmp;
        for(int i=0;i<nums.size();i++){
            tmp=target-nums[i];
            if(mp.find(tmp)!=mp.end()){
                return {mp[tmp],i};
            }
            mp[nums[i]]=i;
        }
        return{-1,-1};
    }
};
