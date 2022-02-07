class Solution {
    private int maxAmount(int nums[],int l,int r){
        int n = (r - l + 1);
        int dp[] = new int[n];
        if(n == 1) return nums[l];
        dp[0] = nums[l];
        dp[1] = Math.max(nums[l],nums[l+1]);
        
        for(int i=2;i<n;i++){
            dp[i] = Math.max(dp[i-1],dp[i-2] + nums[l + i]);
        }
        
        return Math.max(dp[n-1],dp[n-2]);
    }
    public int rob(int[] nums) {
        
        int n = nums.length;
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return Math.max(nums[0],nums[1]);
        return Math.max(maxAmount(nums,0,n-2),maxAmount(nums,1,n-1));
    }
}