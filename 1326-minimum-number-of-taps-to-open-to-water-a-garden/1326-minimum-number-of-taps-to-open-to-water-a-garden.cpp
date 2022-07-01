class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mn = 0,mx = 0;
        int open = 0;
        while(mx < n) {
            for(int i=0;i<ranges.size();i++) {
                if((i - ranges[i]) <= mn && (i+ranges[i]) > mx) {
                    mx = i + ranges[i];
                }
            }
            
            if(mn == mx) return -1;
            
            open++;
            mn = mx;
        }
        return open;
    }
};