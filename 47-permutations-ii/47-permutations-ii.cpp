class Solution {
public:
    void helper(int idx, vector<int>& nums, vector<vector<int>>& res){
        if(idx == nums.size()) res.push_back(nums);
        
        unordered_set<int> st;
        for(int i = idx; i<nums.size(); i++){
            
            if(st.find(nums[i]) == st.end()) {
                 swap(nums[i], nums[idx]);
                helper(idx+1, nums, res);
                swap(nums[i], nums[idx]);
                st.insert(nums[i]);
            }
           
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        helper(0, nums, res);
        return res;
    }
};