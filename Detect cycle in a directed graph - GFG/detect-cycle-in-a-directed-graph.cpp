// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src,vector<int> adj[],vector<int> &dp){
        if(dp[src] != 0){
            return dp[src] == -1;
        }
        dp[src] = -1;
        for(auto &node:adj[src]){
            if(dfs(node,adj,dp)){
                return true;
            }
        }
        dp[src] = 1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> dp(V,0);
        for(int i=0;i<V;i++){
            if(dfs(i,adj,dp)){
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends