// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(vector<int> edges[],int s,int d,int &count,vector<int> &vis){
        
        if(s==d){
            count++;
            return;
        }
        vis[s] = 1;
        
        for(auto v:edges[s]){
            if(!vis[v]) dfs(edges,v,d,count,vis);
        }
        vis[s] = 0; //Backtracking
        
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	     int count = 0;
	     vector<int> adj[n];
	     for(int i=0;i<edges.size();i++){
	         adj[edges[i][0]].push_back(edges[i][1]);
	     }
    	 vector<int> vis(n,0);
    	 dfs(adj,s,d,count,vis);
    	 return count;
	}
	
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends