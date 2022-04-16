class Solution {
public:
    int solve(vector<int> &nums,int idx,vector<int> &dp){
        
        if(idx>=nums.size()-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        if(nums[idx]==0) return dp[idx] = 1e5; //Not possible
        else{
            int ans = 1e5;
            for(int i=1;i<=nums[idx];i++){
                int curr = 1+solve(nums,idx+i,dp);
                ans = min(curr,ans);
            }
            return dp[idx] = ans; //after exploring all the possibilities if not possible
        }
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1,-1);
        return solve(nums,0,dp);
    }
};