class Solution {
    
    int original[];
    int array[];
    public Solution(int[] nums) {
        original = new int[nums.length];
        array = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            original[i] = nums[i];
            array[i] = nums[i];
        }
    }
    private Random rand = new Random();
     private List<Integer> getArrayCopy() {
        List<Integer> asList = new ArrayList<Integer>();
        for (int i = 0; i < array.length; i++) {
            asList.add(array[i]);
        }
        return asList;
    }
    public int[] reset() {
        return original;
    }
    
    public int[] shuffle() {
        List<Integer> aux = getArrayCopy();

        for (int i = 0; i < array.length; i++) {
            int removeIdx = rand.nextInt(aux.size());
            array[i] = aux.get(removeIdx);
            aux.remove(removeIdx);
        }

        return array;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */