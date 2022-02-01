class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(n == 0) return -1;
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        int X[] = {0,0,1,-1,1,1,-1,-1};
        int Y[] = {1,-1,0,0,1,-1,1,-1};
        int count = 0;
        while(!q.empty()){
            int sz =q.size();
            count++;
            for(int i=0;i<sz;i++){
                auto [x,y] = q.front();
                q.pop();
                if(x == n -1 && y == n - 1){
                    return count;
                }
                for(int j=0;j<8;j++){
                    int nx = X[j] + x;
                    int ny = Y[j] + y;
                    if(nx>=0 && ny>=0 && nx < n && ny < n && grid[nx][ny] == 0){
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};