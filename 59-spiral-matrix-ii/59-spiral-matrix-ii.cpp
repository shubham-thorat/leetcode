class Solution {
public:
    int floorMod(int x,int y) {
        return ((x%y) + y) % y;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));
        
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int d = 0,cnt = 1;
        int row = 0,col = 0;
        

        while(cnt <= n * n){
            v[row][col] = cnt++;
            int r = floorMod(row + dir[d][0],n);
            int c = floorMod(col + dir[d][1],n);
            
            if(v[r][c] != 0) d = (d+1)%4;
            
            row += dir[d][0];
            col += dir[d][1];
        }
        return v;
    }
};