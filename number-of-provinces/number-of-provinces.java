class Solution {
    public void union(int A,int B,int parent[]){
        parent[A] = B;
    }
    public int find(int src,int parent[]){
        if(parent[src] == src){
            return src;
        }
        else {
            return parent[src] = find(parent[src],parent);
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        
        int parent[] = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                   int parentA = find(i,parent);
                   int parentB = find(j,parent);
                   
                    if(parentA != parentB){
                        union(parentA,parentB,parent);
                    }
                }
            }
        }
        
        HashSet<Integer> sets = new HashSet<>();
        for(int i=0;i<n;i++){
            sets.add(find(i,parent));
        }
        return sets.size();
    }
}