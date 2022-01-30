class Solution {
    class Union {
        int rank;
        int parent;
        Union(int rank,int parent){
            this.rank = rank;
            this.parent = parent;
        }
        Union(){

        }
    }
    
    public void union(int A,int B,Union nums[]){
        if(nums[A].rank > nums[B].rank){
            nums[B].parent = A;
        }
        else if(nums[A].rank < nums[B].rank){
            nums[A].parent = B;
        }
        else {
            nums[A].parent = B;
            nums[B].rank += 1;
        }
    }
    public int find(int src,Union nums[]){
        if(nums[src].parent == src){
            return src;
        }
        else {
            return nums[src].parent = find(nums[src].parent,nums);
        }
    }
  
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        
        Union parent[] = new Union[n];
        for(int i=0;i<n;i++){
            parent[i] = new Union(1,i);
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