class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        
        HashMap<Integer,Integer> freq = new HashMap<Integer,Integer>();
        for(int i=0;i<nums3.length;i++){
            for(int j=0;j<nums4.length;j++){
                int sum = nums3[i] + nums4[j];
                freq.put(sum,freq.getOrDefault(sum,0) + 1);
            }
        }
        
        int ans = 0;
        for(int i=0;i<nums1.length;i++){
            for(int j=0;j<nums2.length;j++){
                int val = 0 - (nums1[i] + nums2[j]);           
                ans += freq.getOrDefault(val,0);
            }
        }
        return ans;
    }
}