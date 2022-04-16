class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> seen(52,0);
        
        for(auto &e:ranges) {
            seen[e[0]] += 1;
            seen[e[1] + 1] -= 1;
        }
        
        for(int i=1;i<52;i++){
            seen[i] += seen[i-1];
        }
        
        for(int i=left;i<=right;i++){
            if(seen[i] == 0) return false;
        }
        return true;
    }
};