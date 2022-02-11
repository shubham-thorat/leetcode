class Solution {
public:
    int inf = (int)(1e6);
    int helper(vector<int> &coins,int amount,int n,vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(n == 0){
            return inf;
        }
        
        if(dp[amount][n] != -1){
            return dp[amount][n];
        }
        int opt1 = inf;
        if(amount >= coins[n-1]){
            opt1 = helper(coins,amount - coins[n-1],n,dp) + 1;
        }
        int opt2 = helper(coins,amount,n-1,dp);
        
        return dp[amount][n] = min(opt1,opt2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1,vector<int>(amount + 1,0));
        
        for(int coin = 0;coin <= n;coin++){
            for(int cost = 0;cost <= amount;cost += 1){
                // dp[coin][cost] = inf;
                if(cost == 0){
                    dp[coin][cost] = 0;
                }
                else if(coin == 0){
                    dp[coin][cost] = inf;
                }
                else {
                    if(cost >= coins[coin - 1]){
                        dp[coin][cost] = min(dp[coin-1][cost],dp[coin][cost - coins[coin-1]] + 1);
                    }
                    else {
                        dp[coin][cost] = dp[coin - 1][cost];
                    }
                }
            }
        }
        return dp[n][amount] >= inf ? -1 : dp[n][amount];
    }
};