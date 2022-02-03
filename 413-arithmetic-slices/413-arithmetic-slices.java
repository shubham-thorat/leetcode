class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        int prev = 0;
        int ans = 0;
        for(int i=2;i<n;i++){
            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){
                prev += 1;
            }
            else prev = 0;
            ans += prev;
        }
        return ans;
    }
}