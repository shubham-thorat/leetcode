class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n == 0 || n == 1) return 0;
        int minvalue = prices[0];
        
        int ans = 0;
        for(int i=1;i<n;i++){
            ans = Math.max(ans,prices[i] - minvalue);
            minvalue = Math.min(minvalue,prices[i]);
        }
        return ans;
    }
}