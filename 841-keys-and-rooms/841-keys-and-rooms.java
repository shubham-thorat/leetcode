class Solution {
    void dfs(int vis[],List<List<Integer>> rooms,int idx){
        vis[idx] = 1;
        
        for(int i=0;i<rooms.get(idx).size();i++){
            if(vis[rooms.get(idx).get(i)] != 1){
                dfs(vis,rooms,rooms.get(idx).get(i));
            }
        }
    }
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        int vis[] = new int[n];
        
        dfs(vis,rooms,0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
}