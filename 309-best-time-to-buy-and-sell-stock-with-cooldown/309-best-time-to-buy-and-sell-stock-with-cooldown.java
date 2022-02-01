class Solution {
    public int maxProfit(int[] prices) {
        
        int n = prices.length;
        if(n == 0 || n == 1) return 0;
        int dp[][] = new int[n][2];
        
        dp[n-1][0] = 0;
        dp[n-1][1] = prices[n-1];
        
        for(int i=n-2;i>=0;i--){
            //buy
            dp[i][0] = Math.max(-prices[i] + dp[i+1][1],dp[i+1][0]);
            
            //sell
            
            dp[i][1] = Math.max(prices[i] + (i + 2 < n ? dp[i+2][0] : 0),dp[i+1][1]);
        }
        
        return dp[0][0];
    }
}