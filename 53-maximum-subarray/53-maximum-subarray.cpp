class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        // vector<int> dp(N,INT_MIN);
        
        int maxCurrent = nums[0];
        int ans = nums[0];
        for(int i=1;i<N;i++) {
            maxCurrent = max(maxCurrent + nums[i],nums[i]);
            ans = max(ans,maxCurrent);
        }
        return ans;
        
    }
};