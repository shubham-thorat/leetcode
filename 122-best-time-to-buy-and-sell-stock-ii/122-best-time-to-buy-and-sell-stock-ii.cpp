class Solution {
public:
//     int maxProfit(vector<int>& prices) {
        
//     }
    
    int helper(int i, int b, vector<int> &A,vector<vector<int>> &dp){
        if(i==A.size()) return 0;
        int a=0;

            if(dp[i][b] != -1) return dp[i][b];
        if(b==0){
            int x=helper(i+1,0,A,dp);
            int y=-A[i]+helper(i+1,1,A,dp);
            a=max(x,y);
        }
        else{
            int x= A[i] + helper(i+1,0,A,dp);
            int y= helper(i+1,1,A,dp);
            a=max(x,y);
        }
        return dp[i][b] = a;
    }
    int maxProfit(vector<int> &A) {
        if(A.size()<=1) return 0; 
        vector<vector<int>> dp(A.size(),vector<int>(2,-1));
        int n=A.size(), b=0;
        return helper(0,b,A,dp);
    }
};