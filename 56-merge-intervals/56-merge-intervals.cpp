class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 0) return intervals;
       
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        });
         int x = intervals[0][0];
        int y = intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(y < intervals[i][0]){
                ans.push_back({x,y});
                x = intervals[i][0];
                y = intervals[i][1];
            }
            else {
                x = min(x,intervals[i][0]);
                y = max(y,intervals[i][1]);
            }
        }
        ans.push_back({x,y});
        return ans;
    }
};