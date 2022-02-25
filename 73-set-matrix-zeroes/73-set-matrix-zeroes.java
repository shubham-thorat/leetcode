class Solution {
    public void setZeroes(int[][] matrix) {
        int no_row = matrix.length;
        int no_col = matrix[0].length;
        
        int clone[][] = new int[no_row][no_col];        
        for(int row = 0;row < no_row; row++){
            for(int col=0;col < no_col; col++){
                clone[row][col] = matrix[row][col];
            }
        }
        
        for(int row = 0;row < no_row;row++){
            for(int col=0;col < no_col; col++){
                if(clone[row][col] == 0){
                    for(int i=0;i<no_row;i++){
                        matrix[i][col] = 0;    
                    }
                    
                    for(int i=0;i<no_col;i++){
                        matrix[row][i] = 0;
                    }
                }
            }
        }
    }
}