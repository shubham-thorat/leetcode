class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int val = 1;
        int n = nums.size();
        vector<int> ans(n,1);
        
        for(int i=0;i<n;i++) {
            ans[i] = val;
            val = val * nums[i];
        }
        val = 1;
        for(int i=n-1;i>=0;i--) {
            ans[i] = ans[i] * val;
            val = val * nums[i];
        }
        return ans;
    }
};