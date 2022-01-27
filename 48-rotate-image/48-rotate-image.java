class Solution {
    public void Transpose(int matrix[][]){
        for(int i=0;i<matrix.length;i++){
            for(int j=i+1;j<matrix.length;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
    public void reverse(int nums[]){
        int l = 0,r = nums.length - 1;
        while(l <= r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
    public void rotate(int[][] matrix) {
        
        Transpose(matrix);
        
        //reverse every row
        
        for(int i=0;i<matrix.length;i++){
            reverse(matrix[i]);
        }
    }
}