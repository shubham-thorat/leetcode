class Solution {
public:
    int helper(vector<int> &arr,vector<vector<int>> &dp,int l,int r,vector<vector<int>> &memo){
        if(l == r) return 0;
        
        if(memo[l][r] != -1) return memo[l][r];
        int ans = (1<<30);
        for(int i=l;i<r;i++){
            ans = min(ans,dp[l][i] * dp[i+1][r] + helper(arr,dp,l,i,memo) + helper(arr,dp,i+1,r,memo));
        }
        return memo[l][r] = ans;
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(41,vector<int>(41,0));
        vector<vector<int>> memo(41,vector<int>(41,-1));
        int n = arr.size();
        for(int i=0;i<n;i++){
            int maxi = arr[i];
            for(int j=i;j<n;j++){
                maxi = max(maxi,arr[j]);
                dp[i][j] = maxi;
            }
        }
        
        return helper(arr,dp,0,n-1,memo);
    }
};