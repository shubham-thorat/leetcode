// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
      int solve(string s,int lo,int hi,vector<vector<int>> &dp) {
        if(lo > hi) return 0;
        if(lo == hi) return 1;
        if(dp[lo][hi] != -1) return dp[lo][hi];
        if(s[lo] == s[hi]) return dp[lo][hi] = 2 + solve(s,lo + 1,hi - 1,dp);
        else return dp[lo][hi] = max(solve(s,lo+1,hi,dp),solve(s,lo,hi-1,dp));
      }
    int countMin(string s){
        //complete the function here
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return n - solve(s,0,n-1,dp);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends