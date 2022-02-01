class Solution {
    int helper(int nums[],int i,int flag,int dp[][]){
        if(i >= nums.length){
            return 0;
        }
        if(dp[i][flag] != -1) return dp[i][flag];
        
        if(flag == 0){
            int opt1 = helper(nums,i+1,1,dp) - nums[i];
            int opt2 = helper(nums,i+1,0,dp);
            return dp[i][flag] = Math.max(opt1,opt2);
        }
        else {
            int opt1 = helper(nums,i+1,0,dp) + nums[i];
            int opt2 = helper(nums,i+1,1,dp);
            return dp[i][flag] = Math.max(opt1,opt2);
        }
    }
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n][2];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return helper(prices,0,0,dp);
    }
}