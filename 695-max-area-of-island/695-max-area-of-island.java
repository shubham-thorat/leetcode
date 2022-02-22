class Solution {
    public int bfs(int r,int c,int grid[][]){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{r,c});
        int count = 0;
        grid[r][c] = 0;
        int X[] = new int[]{1,-1,0,0};
        int Y[] = new int[]{0,0,1,-1};
        int n = grid.length;
        int m = grid[0].length;
        while(!q.isEmpty()){
            r = q.peek()[0];
            c = q.peek()[1];
            q.poll();
            
            for(int i=0;i<4;i++){
                int nx = r + X[i];
                int ny = c + Y[i];
                
                if(nx >=0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                    q.add(new int[]{nx,ny});
                    grid[nx][ny] = 0;
                }
            }
            count++;
        }
        return count;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int ans = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j] == 1)
                    ans = Math.max(ans,bfs(i,j,grid));
            }
        }
        return ans;
    }
}