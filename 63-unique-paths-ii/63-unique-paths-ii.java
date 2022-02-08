class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length;
        if(m == 0) return 0;
        int n = grid[0].length;
        
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return 0;
        }
        int dp[][] = new int[2][n];
        dp[0][0] = 1;
        for(int i=1;i<n;i++){
            dp[0][i] = (grid[0][i] == 0 ? dp[0][i-1] : 0);
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j == 0){
                    dp[i%2][j] = (grid[i][j] == 1 ? 0 : dp[(i+1)%2][j]);
                }
                else {
                    dp[i%2][j] = grid[i][j] == 1 ? 0 : dp[(i+1)%2][j] + dp[i%2][j-1];
                }
            }
        }
        return dp[(m+1)%2][n-1];
    }
}