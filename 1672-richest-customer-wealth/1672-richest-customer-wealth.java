class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxvalue = 0;
        for(int nums[]:accounts){
            int sum = 0;
            for(int val:nums){
                sum += val;
            }
            maxvalue = Math.max(maxvalue,sum);
        }
        return maxvalue;
    }
}