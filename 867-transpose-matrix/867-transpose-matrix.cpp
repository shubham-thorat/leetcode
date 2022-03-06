class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return matrix;
        int m = matrix[0].size();
        vector<vector<int>> transpose(m,vector<int>(n));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
};