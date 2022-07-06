class Solution {
public:
    void solve(unordered_map<int,int> &mp,vector<int> &curr,int n,vector<vector<int>> &ans) {
        if(n == 0) {
            ans.push_back(curr);
            return;
        }
        
        for(auto &[val,cnt]:mp) {
            
            if(cnt <= 0) continue;
            
            cnt--;
            curr.push_back(val);
            solve(mp,curr,n-1,ans);
            curr.pop_back();
            cnt++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> ans;
        unordered_map<int,int> mp;
        
        for(auto &e:nums) mp[e] += 1;
        
        int n = nums.size();
        vector<int> curr;
        solve(mp,curr,n,ans);
        return ans;
    }
};