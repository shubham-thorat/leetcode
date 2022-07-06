class Solution {
public:
    void permuteUniqueUtil(vector<int> &nums,int idx,set<vector<int>> &ans) {
        if(idx == nums.size()) {
            ans.insert(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++) {
            // if(i > idx && nums)
            swap(nums[i],nums[idx]);
            permuteUniqueUtil(nums,idx + 1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         set<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        permuteUniqueUtil(nums,0,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};