// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    void dfs(int curr,stack<int> &st,vector<bool> &vis,vector<int> adj[]){
        vis[curr] = true;
        for(auto e:adj[curr]){
            if(vis[e] == false){
                dfs(e,st,vis,adj);
            }
        }
        st.push(curr);
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	   stack<int> st;
	   vector<bool> vis(V,0);
	   for(int i=0;i<V;i++){
	       if(vis[i] == false){
	           dfs(i,st,vis,adj);
	       }
	   }
	   
	   fill(vis.begin(),vis.end(),false);
	   dfs(st.top(),st,vis,adj);
	   for(int i=0;i<V;i++){
	       if(vis[i] == false) return -1;
	   }
	   return st.top();
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends