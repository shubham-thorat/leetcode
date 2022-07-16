class Solution {
public:
    int solve(int m,int n,int move,int r,int c,vector<vector<vector<int>>> &dp) {
         if(r < 0 || c < 0 || r == m || c==n) {
            return 1;
        }
        if(move == 0) return 0;
        
        if(dp[r][c][move] != -1) return dp[r][c][move];
        int X[] = {0,0,1,-1};
        int Y[] = {1,-1,0,0};
        
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i=0;i<4;i++) {
            ans += solve(m,n,move - 1,r + X[i],c + Y[i],dp);
            ans = ans % mod;
        }
         return dp[r][c][move] = ans;
    }
    int findPaths(int m, int n, int move, int r, int c) {
        
        vector<vector<vector<int>>> dp(m + 1,vector<vector<int>>(n + 1,vector<int>(move + 1,-1))); 
        
        return solve(m,n,move,r,c,dp);
    }
};