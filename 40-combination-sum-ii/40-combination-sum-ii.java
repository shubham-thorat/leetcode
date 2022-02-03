class Solution {
       private void possibleComb(int candidates[],int target,List<List<Integer>> results,int index,ArrayList<Integer> comb,int sum){
        
        if(sum == target){
            results.add(new ArrayList<Integer>(comb));
            return;
        }
         
        if(index >= candidates.length) return;
        
        for(int i=index;i<candidates.length;i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;   
            
            if(sum + candidates[i] <= target){
                comb.add(candidates[i]);
                possibleComb(candidates,target,results,i + 1,comb,sum + candidates[i]);   
                comb.remove(comb.size() - 1);
            }
        }
        
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
         List<List<Integer>> results = new ArrayList<>();
         Arrays.sort(candidates);
         possibleComb(candidates,target,results,0,new ArrayList<Integer>(),0);
        return results;
    }
}