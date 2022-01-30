class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid){
        int X[] = {0,0,1,-1};
        int Y[] = {1,-1,0,0};
        grid[i][j] = '0';
        for(int k=0;k<4;k++){
            int nx = X[k] + i;
            int ny = Y[k] + j;
            if(nx >=0 && ny>= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '1'){
                dfs(nx,ny,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};