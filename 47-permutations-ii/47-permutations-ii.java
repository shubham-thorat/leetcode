class Solution {
    public void backtrack(List<List<Integer>> results,ArrayList<Integer> comb,HashMap<Integer,Integer> freq,int N){
        if(comb.size() == N){
            results.add(new ArrayList<Integer>(comb));
            return;
        }
        
        for(Map.Entry<Integer,Integer> entry:freq.entrySet()){
            int val = entry.getKey();
            int count = entry.getValue();
            if(count == 0) continue;
            
            freq.put(val,count - 1);
            comb.add(val);
            backtrack(results,comb,freq,N);
            freq.put(val,count);
            comb.remove(comb.size() - 1);
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        HashMap<Integer,Integer> freq = new HashMap<>();
        for(int val:nums){
            freq.put(val,freq.getOrDefault(val,0) + 1);
        }
        int N = nums.length;
        backtrack(results,new ArrayList<Integer>(),freq,N);
        return results;
    }
}