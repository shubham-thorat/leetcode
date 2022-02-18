class Solution {
public:
    void dfs(vector<int> &seen,vector<vector<int>> &graph,int src){
        seen[src] = 1;
        for(auto e:graph[src]){
            if(seen[e] == 0){
                dfs(seen,graph,e);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& arr) {
        
        if(arr.size() < n-1) return -1;
        vector<int> seen(n,0);
        
        vector<vector<int>> graph(n);
        for(int i=0;i<arr.size();i++){
            graph[arr[i][0]].push_back(arr[i][1]);
            graph[arr[i][1]].push_back(arr[i][0]);
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(seen[i] == false){
                dfs(seen,graph,i);
                cnt++;
            }
        }
        
        return (cnt - 1);
    }
};