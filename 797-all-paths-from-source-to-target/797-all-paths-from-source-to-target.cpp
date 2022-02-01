class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<int> path,vector<vector<int>> &ans,int curr){
        
        if(curr == graph.size() - 1){
            ans.push_back(path);
            return;
        }
        
        for(auto e:graph[curr]){
            path.push_back(e);
            dfs(graph,path,ans,e);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        dfs(graph,path,ans,0);
        return ans;
    }
};