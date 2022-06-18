// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(vector<int> &vertices,int vertex,int color,bool graph[101][101]) {
    
    for(int i=0;i<101;i++) {
        if(graph[vertex][i] == true && vertex  != i && vertices[i] == color) {
            return false;
        }
    }
    return true;
}
bool solve(int vertex,bool graph[101][101],int m,int n,vector<int> &vertices) {
    if(vertex == n) {
        return true;
    }
    
    for(int c=1;c<=m;c++) {
        if(isSafe(vertices,vertex,c,graph)) {
            vertices[vertex] = c;
            bool iscolored = solve(vertex + 1,graph,m,n,vertices);
            if(iscolored) return true;
            vertices[vertex] = 0;
        }
    }
    
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    vector<int> vertices(n,0);
    return solve(0,graph,m,n,vertices);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends