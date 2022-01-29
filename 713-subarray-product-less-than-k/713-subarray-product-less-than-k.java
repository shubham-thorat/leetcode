class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int sum = 1;
        if(k <= 1) return 0;
        int count = 0, j =0;
        for(int i=0;i<nums.length;i++){
           sum = sum * nums[i];
            
            while(sum >= k && j <= i){
                sum = (sum/nums[j]);
                j++;
            }
            count += (i - j + 1);
        }
        return count;
        
    }
}