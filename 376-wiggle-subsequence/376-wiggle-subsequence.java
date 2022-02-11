class Solution {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        if(n <= 1) return n;
        int dp[] = new int[n];
        Arrays.fill(dp,1);
        int ans = 1;
        int k = 0;
        while(k < nums.length - 1 && nums[k] == nums[k+1]) k++;
        if(k == nums.length - 1) return 1;
        
        if(nums[k+1] - nums[k] > 0){
            for(int i=k+1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(dp[j] % 2 == 0){
                        if(nums[j] > nums[i]){
                            dp[i] = Math.max(dp[i],dp[j] + 1);
                        }
                    }
                    else {
                        if(nums[j] < nums[i]){
                            dp[i] = Math.max(dp[i],dp[j] + 1);
                        }
                    }
                }
                ans = Math.max(ans,dp[i]);
            }
            return ans;
        }
        else {
            for(int i=k+1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(dp[j] % 2 == 0){
                        if(nums[j] < nums[i]){
                            dp[i] = Math.max(dp[i],dp[j] + 1);
                        }
                    }
                    else {
                        if(nums[j] > nums[i]){
                            dp[i] = Math.max(dp[i],dp[j] + 1);
                        }
                    }
                }
                ans = Math.max(ans,dp[i]);
            }
            return ans;
        }
    }
}