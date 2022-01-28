class Solution {
public:
    int helper(vector<int> &nums,int index,vector<int> &dp){
        if(index >= nums.size() - 1){
            return 0;
        }
        
        if(dp[index] != -1) return dp[index];
        int ans = nums.size() + 1;
       for(int i=1;i<=nums[index];i++){
           int temp = helper(nums,index + i,dp) + 1;
           ans = min(ans,temp);
       }
        return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};