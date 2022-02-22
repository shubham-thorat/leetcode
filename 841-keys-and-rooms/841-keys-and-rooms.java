class Solution {
    
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean vis[] = new boolean[n];
        
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        vis[0] = true;
        while(!q.isEmpty()){
            int top = q.poll();
            
            for(Integer node:rooms.get(top)){
                if(vis[node] == false){
                    q.add(node);
                    vis[node] = true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(vis[i] == false) return false;
        }
        return true;
    }
}