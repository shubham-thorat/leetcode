class Solution {
    public int maxProduct(int[] nums) {
        if(nums.length == 0) return 0;
        int n = nums.length;
        
        int max = nums[0];
        int min = nums[0];
        int result = nums[0];
        for(int i=1;i<n;i++){
            
            int curr_max = Math.max(max * nums[i],Math.max(min * nums[i],nums[i]));
            int curr_min = Math.min(max * nums[i],Math.min(min * nums[i],nums[i]));
            
            max = curr_max;
            min = curr_min;
            
            if(max > result){
                result = max;
            }
        }
        return result;
    }
}