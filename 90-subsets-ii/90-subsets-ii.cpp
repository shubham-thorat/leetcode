class Solution {
public:
    void helper(set<vector<int>> &ans,vector<int> &curr,vector<int> &nums,int ind){
        if(ind >= nums.size()){
            ans.insert(curr);
            return;
        }
        
        helper(ans,curr,nums,ind + 1);
        curr.push_back(nums[ind]);
        helper(ans,curr,nums,ind + 1);
        curr.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> curr;
        set<vector<int>> ans;
        helper(ans,curr,nums,0);
        vector<vector<int>> res;
        for(auto e:ans){
            res.push_back(e);
        }
        return res;
    }
};