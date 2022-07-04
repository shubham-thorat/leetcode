class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int source,vector<int> &vis) {
        if(vis[source] == 1) {
            return true;
        }
        
        if(vis[source] == 0) {
            vis[source] = 1;
            for(auto &e:adj[source]) {
                if(dfs(adj,e,vis)) {
                    return true;
                }
            }
        }
        vis[source] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        
        for(int i=0;i<pre.size();i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++) {
            if(dfs(adj,i,vis)) {
                return false;
            }
        }
        return true;
    }
};