class Solution {
    public int subarraySum(int[] nums, int k) {
        
        //brute force
        
        int len = nums.length;
        int count = 0;
        for(int i=0;i<len;i++) {
            int sum = 0;
            for(int j=i;j<len;j++) {
                sum += nums[j];
                if(sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
}