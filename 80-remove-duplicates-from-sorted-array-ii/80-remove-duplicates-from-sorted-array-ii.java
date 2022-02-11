class Solution {
    public int removeDuplicates(int[] nums) {
        int slow=2,fast=2;
        int n=nums.length;
        if(n<3)
            return n;
        while(fast<n){
            if(nums[slow-2]!=nums[fast]){
                nums[slow++]=nums[fast++];
            }
            else
                fast++;
        }
        return slow;
    }
}