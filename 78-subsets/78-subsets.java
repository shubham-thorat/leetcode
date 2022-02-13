class Solution {
    private void helper(List<List<Integer>> result,int nums[],int index,ArrayList<Integer> set){
        if(index >= nums.length){
            result.add(new ArrayList<Integer>(set));
            return;
        }
        
         helper(result,nums,index + 1,set);
        set.add(nums[index]);
        helper(result,nums,index + 1,set);
        set.remove(set.size() - 1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        
        helper(result,nums,0,new ArrayList<Integer>());
        return result;
    }
}