class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int index1 = -1,index2 = -1;
        int i = n-2,j = 0,t = 0;
        while(i>=0){
            if(nums[i] < nums[i+1]){
                index1 = i;
                break;
            }
            i--;
        }
        if(index1 == -1) {
            i = 0; j = n-1;
            while(i < j){
                t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i++;
                j--;
            }
            return;
        }
        i = n-1;
        while(i >= index1){
            if(nums[i] > nums[index1]){
                index2 = i;
                break;
            }
            i--;
        }
        
         t = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = t;
        
        i = index1 + 1;
      j = n-1;
        while(i < j){
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
            j--;
        }
    }
}