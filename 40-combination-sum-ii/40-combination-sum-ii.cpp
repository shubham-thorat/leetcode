class Solution {
public:
    void helper(vector<int> &nums,int target,int ind,vector<vector<int>> &ans,vector<int> &curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(ind == nums.size() || target < 0) return;
        
        for(int j=ind;j<nums.size();j++){
            if(j > ind && nums[j] == nums[j-1]) continue;
            curr.push_back(nums[j]);
            helper(nums,target - nums[j],j+1,ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums,target,0,ans,curr);
        return ans;
    }
};