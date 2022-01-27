class Solution {
    int helper(int nums[],int l,int r){
        
        int n = (r - l + 1);
        int dp[] = new int[r - l + 1];
        dp[0] = nums[l];
        if(l == r) return dp[0];
        dp[1] = Math.max(nums[l],nums[l+1]);
        if(r == l + 1){
            return dp[1];
        }
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
        
        int opt1 = helper(nums,0,n-2);
        int opt2 = helper(nums,1,n-1);
        return Math.max(opt1,opt2);
    }
}