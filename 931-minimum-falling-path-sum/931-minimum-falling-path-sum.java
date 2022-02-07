class Solution {
    int min(int a,int b,int c){
        return Math.min(a,Math.min(b,c));
    }
    public int minFallingPathSum(int[][] matrix) {
        
        int n = matrix.length;
        
        if(n == 0) return 0;
        int m = matrix[0].length;
        for(int i=1;i<matrix.length;i++){
            for(int j=0;j<matrix[i].length;j++){
                int val = matrix[i][j];
                
                int opt1 = matrix[i-1][j];
                int opt2 = (j>0 ? matrix[i-1][j-1] : Integer.MAX_VALUE);
                int opt3 = (j < m -1 ? matrix[i-1][j+1] : Integer.MAX_VALUE);
                
                matrix[i][j] = min(opt1,opt2,opt3) + val;
            }
        }
        
        int val = Integer.MAX_VALUE;
        for(int i=0;i<m;i++){
            val = Math.min(matrix[n-1][i],val);
        }
        return val;
    }
}