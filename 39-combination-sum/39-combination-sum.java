class Solution {
    private void possibleComb(int candidates[],int target,List<List<Integer>> results,int index,ArrayList<Integer> comb,int sum){
        
        if(sum == target){
            results.add(new ArrayList<Integer>(comb));
            return;
        }
        if(index >= candidates.length) return;
        
        if(sum + candidates[index] <= target){
            comb.add(candidates[index]);
            possibleComb(candidates,target,results,index,comb,sum + candidates[index]);   
            comb.remove(comb.size() - 1);
        }
        
        possibleComb(candidates,target,results,index+1,comb,sum);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<>();
        
        possibleComb(candidates,target,results,0,new ArrayList<Integer>(),0);
        return results;
    }
}