class Solution {
    public int subarraySum(int[] nums, int k) {
        
        //brute force
        /*
        int len = nums.length;
        int count = 0;
        for(int i=0;i<len;i++) {
            int sum = 0;
            for(int j=i;j<len;j++) {
                sum += nums[j];
                if(sum == k) {
                    count++;
                }
            }
        }
        return count;
        */
        
        //Optimal
        HashMap<Integer,Integer> sums = new HashMap<>();
        int sum = 0,count = 0;
        sums.put(0,1);
        for(int i=0;i<nums.length;i++) {
            sum += nums[i];
            
            if(sums.containsKey(sum - k)) {
                count += sums.get(sum-k);
            }
            
            sums.put(sum,sums.getOrDefault(sum,0) + 1);
        }
        return count;
        
    }
}