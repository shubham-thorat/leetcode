class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
       int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int sum[m][n];
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(i == 0 && j == 0){
                     sum[i][j] = matrix[i][j];
                 }       
                 else if(i == 0){
                     sum[i][j] = sum[i][j-1] + matrix[i][j];
                 }
                 else if(j == 0){
                     sum[i][j] = sum[i-1][j] + matrix[i][j];
                 }
                 else {
                     sum[i][j] = sum[i-1][j] + sum[i][j-1] + matrix[i][j] -  sum[i-1][j-1]; 
                 }
                //  System.out.println(sum[i][j] + " ");
            }
            // System.out.println();
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                for(int l=i;l<m;l++){
                    for(int r=j;r<n;r++){
                        int opt1 = (i > 0) ? sum[i-1][r] : 0;
                        int opt2 = (j>0)?sum[l][j-1] : 0;
                        int opt3 = (i>0 && j>0) ? sum[i-1][j-1] : 0;
                        int s = sum[l][r] - opt1 - opt2 + opt3;
                        if(s == target){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};