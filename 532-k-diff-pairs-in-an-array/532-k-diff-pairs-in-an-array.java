class Solution {
    public int findPairs(int[] nums, int k) {
       HashMap<Integer,Integer> map = new HashMap<>();
        
        for(int val:nums){
            map.put(val,map.getOrDefault(val,0) + 1);
        }
        
        int ans = 0;
        for(int val:map.keySet()){
            if(k == 0 && map.get(val) > 1){
                ans += 1;
            }
            else if(k != 0 && map.containsKey(val + k)){
                ans += 1;
            }
        }
        return ans;
    }
}