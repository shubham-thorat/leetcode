class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N,INT_MIN);
        
        dp[0] = nums[0];
        int ans = nums[0];
        for(int i=1;i<N;i++) {
            
            dp[i] = max(dp[i-1] + nums[i],nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};