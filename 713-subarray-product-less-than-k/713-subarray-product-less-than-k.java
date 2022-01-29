class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int sum = 1;
        int count = 0;
        for(int i=0;i<nums.length;i++){
            sum = 1;
            for(int j=i;j<nums.length;j++){
                sum = sum * nums[j];
                if(sum < k){
                    count++;
                }
                else {
                    break;
                }
            }
        }
        return count;
        
    }
}