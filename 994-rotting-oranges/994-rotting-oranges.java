class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> q = new LinkedList<>();
        int n = grid.length;
        if(n == 0) return -1;
        int m = grid[0].length;
        int totalorange = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.add(new int[]{i,j});
                }
                if(grid[i][j] != 0) totalorange += 1;
            }
        }
        
        // if(q.size() == 0) return -1;
        
        int X[] = new int[]{0,0,1,-1};
        int Y[] = new int[]{1,-1,0,0};
        int distance = 0;
        System.out.println(totalorange);
        while(!q.isEmpty()){
            
            int sz = q.size();
            totalorange -= sz;
            for(int i=0;i<sz;i++){
                int x = q.peek()[0];
                int y = q.peek()[1]; q.poll();
                
                for(int j=0;j<4;j++){
                    int nx = X[j] + x;
                    int ny = Y[j] + y;
                    
                    if(nx>=0 && ny >=0 && nx <n && ny < m && grid[nx][ny] == 1){
                        q.add(new int[]{nx,ny});
                        grid[nx][ny] = 2;
                    }
                }
            }
            distance++;
        }
        
        return (totalorange == 0 ? Math.max(0,distance - 1) : -1);
    }
}