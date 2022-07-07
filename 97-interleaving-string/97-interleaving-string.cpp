class Solution {
public:
    vector<vector<vector<int>>> dp;
    bool solve(string s1,string s2,string s3,int i,int j,int k) {
        
        if(k == s3.length()) {
            return true;
        }
        int size1 = s1.length();
        int size2 = s2.length();
        int size3 = s3.length();
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        
        if((size1 - i) + (size2 - j) != (size3 - k)) {
            return dp[i][j][k] = false;
        }
        if(i < size1 && j < size2 && s1[i] == s2[j]) {
            if(s1[i] == s3[k]) {
                return dp[i][j][k] = solve(s1,s2,s3,i+1,j,k + 1) || solve(s1,s2,s3,i,j+1,k + 1);  
            }
            else {
                return dp[i][j][k] = false;
            }
        }
        else if(i < size1 && s1[i] == s3[k]) {
            return dp[i][j][k] = solve(s1,s2,s3,i+1,j,k+1);
        }
        else if(j < size2 && s2[j] == s3[k]) {
            return dp[i][j][k] = solve(s1,s2,s3,i,j+1,k+1);
        }
        else {
            return dp[i][j][k] = false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(101,vector<vector<int>>(101,vector<int>(201,-1)));
    
        // vector<vector<vector<int>>> dp(101,vector<vector<int>>(101,vector<int>(201,-1)));
        return solve(s1,s2,s3,0,0,0) || solve(s2,s1,s3,0,0,0);        
    }
};