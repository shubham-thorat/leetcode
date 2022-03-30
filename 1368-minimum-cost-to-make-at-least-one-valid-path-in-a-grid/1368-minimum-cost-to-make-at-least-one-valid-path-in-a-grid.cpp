class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int,int,int>> q;
        q.push({0,0,0});
        int X[] = {0,0,1,-1};
        int Y[] = {1,-1,0,0};
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0] = 0;
        while(!q.empty()){
            auto [x,y,cost] = q.front(); q.pop();
            
            for(int i=0;i<4;i++){
                int nx = X[i] + x;
                int ny = Y[i] + y;
                if(nx>=0 && ny>=0 && nx < m && ny < n){
                    if(grid[x][y] == (i+1)){
                        if(dp[nx][ny] > cost){
                            dp[nx][ny] = cost;
                            q.push({nx,ny,cost});
                        }
                    }
                    else {
                        if(dp[nx][ny] > cost + 1) {
                            dp[nx][ny] = cost + 1;
                            q.push({nx,ny,cost + 1});
                        }
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};