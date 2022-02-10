class Solution {
    public int min(int a,int b,int c){
        return Math.min(a,Math.min(b,c));
    }
    public int maximalSquare(char[][] matrix) {
        int n = matrix.length;
        if(n == 0) return 0;
        int m = matrix[0].length;
        int dp[][] = new int[n][m];
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[i][0] = matrix[i][0] - '0';
            ans = Math.max(ans,dp[i][0]);
        }
        
        for(int i=0;i<m;i++){
            dp[0][i] = matrix[0][i] - '0';
                ans = Math.max(ans,dp[0][i]);
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1;
                }
                else {
                    dp[i][j] = 0;
                }
                
                ans = Math.max(ans,dp[i][j]);
            }
        }
        
        return ans * ans;
    }
}