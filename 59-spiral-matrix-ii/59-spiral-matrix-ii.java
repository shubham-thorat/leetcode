class Solution {
    public int[][] generateMatrix(int n) {
        int spiral[][] = new int[n][n];
        int cnt = 1;
        for(int layer = 0;layer < (n+1)/2; layer++){
            
            for(int i=layer;i<(n - layer);i++){
                spiral[layer][i] = cnt++;
            }
            
            for(int i=layer + 1;i<(n - layer);i++){
                spiral[i][n-layer-1] = cnt++;
            }
            
            for(int i=n-layer-2;i>=layer;i--){
                spiral[n-layer-1][i] = cnt++;
            }
            
            for(int i=n-layer-2;i>layer;i--){
                spiral[i][layer] = cnt++;
            }
        }
        return spiral;
    }
}