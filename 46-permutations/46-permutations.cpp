class Solution {
public:
    void solve(vector<int> &nums,int idx,vector<vector<int>> &ans) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        int n = nums.size();
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            solve(nums,idx + 1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> curr;
        
        solve(nums,0,ans);
        return ans;
    }
};