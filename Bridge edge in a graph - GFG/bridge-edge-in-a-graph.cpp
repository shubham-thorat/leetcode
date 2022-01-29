// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to perform DFS on graph.
	void DFS(vector<int> adj[], int v, bool visited[])
	{
	    //marking the current vertex as visited.
        visited[v] = true;
        vector<int>::iterator i;
        
        //traversing over the adjacent vertices.
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        
            //if any vertex is not visited, we call the function  
            //recursively for adjacent node.
            if (!visited[*i]) 
                DFS(adj, *i, visited);
    }
    
    //Function to find whether graph is connected.
    bool isConnected(vector<int> adj[], int V, int one, int two) 
    {
        //using boolean array to mark visited nodes and currently 
        //marking all the nodes as false.
        bool visited[V] = {0};
        memset(visited, false, sizeof(visited));
        
        //finding all reachable vertices from first vertex 
        //and marking them visited.
        DFS(adj, one, visited);
        
        //if second vertex is not visited, we return false else true.
        if (visited[two] == false) 
            return false;
        return true;
    }
    
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        //if graph is not connected, we return false.
        if (!isConnected(adj, V, c, d))
            return 0;
        else
        {
            //we remove edge from undirected graph.
            adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
            adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());
            
            //if graph is connected, we return false else true.
            if (isConnected(adj, V, c, d))
                return 0;
            else
                return 1;
        }
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends