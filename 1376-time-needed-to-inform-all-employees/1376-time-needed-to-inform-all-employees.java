class Solution {
    private int dfs(int src,HashMap<Integer,ArrayList<Integer>> graph,int informTime[]){
        if(graph.get(src) == null || graph.get(src).size() == 0) return 0;
        
        int ans = 0;
        for(Integer node:graph.get(src)){
            ans = Math.max(ans,dfs(node,graph,informTime));
        }
        
        return ans + informTime[src];
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        
        HashMap<Integer,ArrayList<Integer>> graph = new HashMap<>();
        
        for(int i=0;i<n;i++){
            int k = i;
            int v = manager[i];
            if(!graph.containsKey(v)){
                graph.put(v,new ArrayList<Integer>());
            }
            
            graph.get(v).add(k);
        }
        
        return dfs(headID,graph,informTime);
    }
}