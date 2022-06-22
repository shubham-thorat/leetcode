class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = -1;
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                
                if(grid[i][j] == 2 || grid[i][j] == 1) {
                    cnt+=1;
                }
            }
        }
        if(cnt == 0) return 0;
        
        int X[] = {0,0,1,-1};
        int Y[] = {1,-1,0,0};
        while(!q.empty()) {
            int sz = q.size();
            
            while(sz--) {
                cnt--;
                auto [x,y] = q.front();
                q.pop();
                
                for(int i=0;i<4;i++) {
                    int nx = x + X[i];
                    int ny = y + Y[i];
                    if(nx>=0 && ny>=0 && nx < m && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        
        if(cnt == 0) return time;
        else return -1;
    }
};