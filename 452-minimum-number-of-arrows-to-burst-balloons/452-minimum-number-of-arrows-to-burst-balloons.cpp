class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b) {
                return a[1] < b[1];
        }); 
        int totalPoints = points.size();
        
        int lastY = points[0][1];
        int ans = 0;
        
        for(int i=1;i<totalPoints;i++) {
            if(lastY >= points[i][0]) {
                ans++;
            }
            else {
                lastY = points[i][1];
            }
        }
        
        
        return totalPoints - ans;
    }
};