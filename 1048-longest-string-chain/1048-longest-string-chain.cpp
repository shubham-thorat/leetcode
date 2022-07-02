class Solution {
public:
    static bool sortByLength(string s1,string s2) {
        return (s1.length() < s2.length());
    }
    
    int longestStrChain(vector<string>& words) {
        if(words.size() == 0) {
            return 0;
        }
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),sortByLength);
        
        int ans = 1;
        for(string str:words) {
            dp[str] = 1;    
            for(int i=0;i<str.length();i++) {
                string curr = str.substr(0,i) + str.substr(i+1);
                if(dp.find(curr) != dp.end()) {
                    dp[str] = max(dp[str],dp[curr] + 1);
                    ans = max(ans,dp[str]);
                }
            }
        }
        return ans;
    }
};