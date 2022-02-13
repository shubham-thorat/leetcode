class Solution {
    int original[];
    int N;
    public Solution(int[] nums) {
        N = nums.length;
        original = nums;
    }
    
    public int[] reset() {
        return original;
    }
    
    public int[] shuffle() {
        Random rand = new Random();
        int result[] = original.clone();
        
        for(int i=1;i<N;i++){
            int index = rand.nextInt(i+1);
            int temp = result[index];
            result[index] = result[i];
            result[i] =  temp;
        }
        return result;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */