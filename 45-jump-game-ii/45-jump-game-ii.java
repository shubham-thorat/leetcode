class Solution {
    public int jump(int[] nums) {
        
        int n = nums.length;
        int max_curr = 0,max_so_far = 0;
        int jump = 0;
        for(int i=0;i<n-1;i++){
            max_so_far = Math.max(max_so_far,i + nums[i]);
            if(i == max_curr){
                jump += 1;
                max_curr = max_so_far;
            }
        }
        return jump;
    }
}