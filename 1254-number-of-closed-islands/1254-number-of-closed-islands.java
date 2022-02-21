class Solution {
    private void dfs(int grid[][],int r,int c){
        grid[r][c] = 1;
        int X[] = new int[]{0,0,1,-1};
        int Y[] = new int[]{1,-1,0,0};
        int n = grid.length;
        int m = grid[0].length;
        for(int i=0;i<4;i++){
            int nx = X[i] + r;
            int ny = Y[i] + c;
            if(nx >=0 && ny >=0 && nx < n&& ny < m && grid[nx][ny] == 0){
                dfs(grid,nx,ny);
            }
        }
    }
    public int closedIsland(int[][] grid) {
        
        int n = grid.length;
        if(n == 0) return 0;
        int m = grid[0].length;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid[i][j] == 0 &&  ((i*j == 0) || i == n-1 || j == m-1)){
                   dfs(grid,i,j);
               }
           }
       }
        
        int count = 0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j] == 0){
                    dfs(grid,i,j);
                    count += 1;
                }
            }
        }
        return count;
    }
}