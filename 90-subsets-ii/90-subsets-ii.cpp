class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int> &curr,vector<int> &nums,int ind){
        ans.push_back(curr);
        
        for(int j=ind;j<nums.size();j++){
            if(j > ind && nums[j] == nums[j-1]) continue;
            curr.push_back(nums[j]);
            helper(ans,curr,nums,j + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> curr;
        vector<vector<int>> ans;
        helper(ans,curr,nums,0);
        return ans;
    }
};