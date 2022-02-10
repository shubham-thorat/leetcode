class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int sum = 0,ans = 0;
        for(int val:nums){
            sum += val;
            if(map.containsKey(sum - k)){
                ans += map.get(sum - k);
            }
            map.put(sum,map.getOrDefault(sum,0) + 1);
        }
        return ans;
    }
}