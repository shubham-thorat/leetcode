class Solution {
public:
    bool helper(string s,int idx,unordered_set<string> &cache,vector<int> &dp) {
        if(idx == s.length()) {
            return true;
        }
        if(dp[idx] != -1) return dp[idx];
        
        for(int i=idx;i<s.length();i++) {
            string str = s.substr(idx,i - idx + 1);
            if(cache.find(str) != cache.end()) {
                bool flag = helper(s,i + 1,cache,dp);
                if(flag) return dp[idx] =  true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> cache;
        vector<int> dp(s.length() + 1,-1);
        for(auto &e:wordDict) {
            cache.insert(e);
        }
        
        return helper(s,0,cache,dp);
    }
};
