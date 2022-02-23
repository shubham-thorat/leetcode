class Solution {
public:
    bool dfs(int src,vector<vector<int>> &graph,vector<int> &nodes_status){
        if(nodes_status[src] != 0){
            return nodes_status[src] == -1; 
        }
        nodes_status[src] = -1;
        for(auto &node:graph[src]){
            if(dfs(node,graph,nodes_status)){
                return true;
            }
        }
        
        nodes_status[src] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> nodes_status(n,0);
        //0-not yet processed
        //1 - processed
        //-1 - in processed
        
        for(int i=0;i<n;i++){
            if(!dfs(i,graph,nodes_status)){
                result.push_back(i);
            }
        }
        return result;
    }
};