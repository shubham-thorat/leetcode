class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> clone(matrix);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[j][n-i-1] = clone[i][j];
            }
        }
    }
};
// i,j => j,i