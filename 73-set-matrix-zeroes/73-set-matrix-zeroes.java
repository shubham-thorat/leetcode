class Solution {
    public void setZeroes(int[][] matrix) {
        int no_row = matrix.length;
        int no_col = matrix[0].length;
        
        boolean isfirstcol = false,isfirstrow = false;
        
         
        for(int i=0;i<no_col;i++){ if(matrix[0][i] == 0) {isfirstrow = true; break; }}
        for(int i=0;i<no_row;i++) { if(matrix[i][0] == 0) {isfirstcol = true; break; }}
        
        for(int row = 1;row < no_row; row++){
            for(int col=1;col < no_col; col++){
                
                if(matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        
        
        for(int row=1;row<no_row;row++){
            for(int col=1;col<no_col;col++){                
                if(matrix[0][col] == 0 || matrix[row][0] == 0){
                    matrix[row][col] = 0;
                }
            }
        }
        
        if(isfirstrow) for(int i=0;i<no_col;i++) matrix[0][i] = 0;
        if(isfirstcol) for(int i=0;i<no_row;i++) matrix[i][0] = 0;
    }
}