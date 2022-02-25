class Solution {
    public void setZeroes(int[][] matrix) {
        int no_row = matrix.length;
        int no_col = matrix[0].length;
        
        int rows[] = new int[no_row];
        int cols[] = new int[no_col];
        
        for(int row = 0;row < no_row; row++){
            for(int col=0;col < no_col; col++){
                if(matrix[row][col] == 0){
                    rows[row] = 1;
                    cols[col] = 1;
                }
            }
        }
        
        for(int row=0;row<no_row;row++){
            for(int col=0;col<no_col;col++){
                if(rows[row] == 1 || cols[col] == 1){
                    matrix[row][col] = 0;
                }
            }
        }
    }
}