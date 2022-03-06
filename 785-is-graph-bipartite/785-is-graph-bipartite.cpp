class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<int> &vis,vector<int> &color,int src,int code,int par){
        vis[src] = 1;
        color[src] = code;
        
        for(auto &e:graph[src]){
            if(vis[e] == 0){
                if(!dfs(graph,vis,color,e,(code ^ 1),src)){
                    return false;
                }
            }
            else if(par != e && vis[e] == 1 && color[e] == code){
                return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0),color(n,-1);
        
        for(int i=0;i<n;i++){
            if(vis[i] == 0)
                if(!dfs(graph,vis,color,i,1,-1))  return false;
        }
        return true;
        
    }
};