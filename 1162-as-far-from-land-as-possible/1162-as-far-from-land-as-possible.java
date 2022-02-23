class Solution {
    public int maxDistance(int[][] grid) {
        Queue<int[]> q = new LinkedList<>();
        int n = grid.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.add(new int[]{i,j});
                }
            }
        }
        
        if(q.size() == 0 || q.size() == (n*n)) return -1;
        int X[] = new int[]{0,0,1,-1};
        int Y[] = new int[]{1,-1,0,0};
        int distance = 0;
        while(!q.isEmpty()){
            
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int x = q.peek()[0];
                int y = q.peek()[1]; q.poll();
                
                for(int j=0;j<4;j++){
                    int nx = X[j] + x;
                    int ny = Y[j] + y;
                    
                    if(nx>=0 && ny >=0 && nx <n && ny < n && grid[nx][ny] == 0){
                        q.add(new int[]{nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            distance++;
        }
        return distance - 1;
    }
}