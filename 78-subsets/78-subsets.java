class Solution {
    void helper(int i,int nums[],List<List<Integer>> a,ArrayList<Integer> arr){
        if(i == nums.length){
            ArrayList<Integer> newnode = new ArrayList<>(arr);
            a.add(newnode);
            return;
        }
        
        helper(i+1,nums,a,arr);
        arr.add(nums[i]);
        helper(i+1,nums,a,arr);
        int index = arr.size() - 1;
        arr.remove(index);
    }
    public List<List<Integer>> subsets(int[] nums) {
        
        ArrayList<Integer> temp = new ArrayList<>();
        temp.add(nums[0]);
        for(int e:nums){
            if(temp.get(temp.size() - 1) != e){
                temp.add(e);
            }
        }
        
        List<List<Integer>> a = new ArrayList<List<Integer>>();
        ArrayList<Integer> arr = new ArrayList<>();
        helper(0,temp.stream().mapToInt(e -> e).toArray(),a,arr);       
        return a;
    }
}