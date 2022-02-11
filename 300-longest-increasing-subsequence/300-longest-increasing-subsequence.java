class Solution {
    // public int lengthOfLIS(int[] nums) {
    //     int n = nums.length;
    //     int dp[] = new int[n];
    //     int ans = 0;
    //     for(int i=0;i<n;i++){
    //         dp[i] = 1;
    //         for(int j=0;j<i;j++){
    //             if(nums[j] < nums[i]){
    //                 dp[i] = Math.max(dp[i],dp[j] + 1);
    //             }
    //         }
    //         ans = Math.max(ans,dp[i]);
    //     }
    //     return ans;
    // }
    public int lengthOfLIS(int[] nums) {
        int[] tails = new int[nums.length];
        int size = 0;
        for (int x : nums) {
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tails[i] = x;
            if (i == size) ++size;
        }
        return size;
    }
}