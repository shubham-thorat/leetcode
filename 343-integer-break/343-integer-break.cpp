class Solution {
public:
    int helper(int n,vector<int> &dp){
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++){
            int opt1 =  max((n - i) *  i, i * helper(n-i,dp));
            ans = max(opt1,ans);
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};