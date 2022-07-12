class Solution {
public:
    bool isSquare(vector<int> &sticks,int idx,int curr_sum,int k,int side,vector<bool> &vis) {
        
        if(k == 0) {
            for(int i=0;i<sticks.size();i++) {
                if(sticks[i] == false) return false;
            }
            return true;
        }
       
        if(curr_sum == side) {
            return isSquare(sticks,0,0,k-1,side,vis);
        }
        if(idx == sticks.size()) return false;
        
        for(int i=idx;i<sticks.size();i++) {
            if(vis[i] == false && curr_sum + sticks[i] <= side) {
                vis[i] = true;
                bool temp = isSquare(sticks,i + 1,curr_sum + sticks[i],k,side,vis);
                if(temp == true) return true;
                vis[i] = false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& sticks) {
        int n = sticks.size();
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += sticks[i];
        }
        
        if(n < 4 || sum%4 != 0) return false;
        int side = sum/4;
        vector<bool> vis(n,false);
        int k = 4;
        return isSquare(sticks,0,0,k,side,vis);
    }
};