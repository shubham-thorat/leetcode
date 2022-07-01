class Solution {
public:
    int solve(vector<int> &nums) {
        unordered_map<int,int> mp;
        
        for(auto &e:nums) mp[e]++;
        int ans = 0;
        for(auto &e:mp) {
            if(e.second > 1) ans++;
        }
        return ans;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n <= 1) return 0;
        
        
        if(k == 0) {
            return solve(nums);
        }
        
        unordered_set<int> st;
        
        
        
        st.insert(nums[0]);
        int ans = 0;
        for(int i=1;i<n;i++) {
            if(nums[i] == nums[i-1]) continue;
            
            if(st.find(nums[i] - k) != st.end()) {
                ans += 1;
            }
            st.insert(nums[i]);
        }
    
        return  ans;
    }
};