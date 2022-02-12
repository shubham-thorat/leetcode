class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        int degree[] = new int[n];
        for(int i=0;i<edges.size();i++){
            degree[edges.get(i).get(1)] += 1;
        }
        
        List<Integer> result = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(degree[i] == 0){
                result.add(i);
            }
        }
        return result;
    }
}