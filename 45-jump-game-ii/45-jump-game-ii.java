class Solution {
    public int jump(int[] nums) {
        
        int n = nums.length;
        if(n <= 1) return 0;        
        int dp[] = new int[n];
        for(int i=1;i<n;i++){
            dp[i] = n;
            for(int j=0;j<i;j++){
                if(j + nums[j] >= i){
                    dp[i] = Math.min(dp[i],dp[j] + 1);
                }
            }
        }
        return dp[n-1];
        
    }
}