class NumMatrix {

    int[][] rangeSum;
    public NumMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        rangeSum = new int[m + 1][n + 1];
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                rangeSum[i + 1][j + 1] = rangeSum[i + 1][j] + rangeSum[i][j + 1] - rangeSum[i][j] + mat[i][j];
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        row1 += 1;
        row2 += 1;
        col1 += 1;
        col2 += 1;
        return rangeSum[row2][col2] - rangeSum[row1-1][col2] - rangeSum[row2][col1-1] + rangeSum[row1-1][col1-1];
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */