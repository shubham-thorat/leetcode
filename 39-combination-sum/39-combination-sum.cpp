class Solution {
public:
    void solve(vector<int> &arr,int idx,int target,vector<int> &path,vector<vector<int>> &result){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(idx >= arr.size() || target < 0) return;
        
        solve(arr,idx + 1,target,path,result);
        path.push_back(arr[idx]);
        
        solve(arr,idx,target - arr[idx],path,result);
        path.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> result;
        
        solve(candidates,0,target,path,result);
        return result;
    }
};