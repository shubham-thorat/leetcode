class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,queue<pair<int,int>> &q,int i,int j)
    {
          int n = grid.size();
        int m = grid[0].size();
        
        // cout << i << " " << j << endl;
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] == true || grid[i][j]==0)return ;
        
        vis[i][j] = true;
        q.push({i,j});
        for(auto x:dir)
        {
            int a = i + x[0];
            int b = j + x[1];
            
            dfs(grid,vis,q,a,b);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,false));
        queue<pair<int,int>> q;
        bool flag = false;
        for(int i=0;i<n && !flag;i++)
        {
            for(int j=0;j<m && !flag;j++)
            {
                if(grid[i][j]==1)
                {
                    // cout << "run";
                    dfs(grid,vis,q,i,j);
                    flag = true;
                    // cout << q.size() << endl;
                }
            }
        }
        
        // cout << q.size() << endl;
        
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto p = q.front();
                q.pop();
                for(auto x:dir)
                {
                    int a = p.first + x[0];
                    int b = p.second + x[1];
                    if(a<0 || b<0 || a>=n || b>=m || vis[a][b])continue ;
                    if(grid[a][b]==1)return level;
                    
                    vis[a][b] = true;
                    q.push({a,b});
                    
                    
                }
                
            }
            level++;
        }
        
        return 0;
        
    }
};