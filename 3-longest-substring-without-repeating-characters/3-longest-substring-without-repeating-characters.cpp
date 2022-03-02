class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int latest = -1;
        unordered_map<char,int> mp;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            
            if(mp.find(s[i]) != mp.end()){
                latest = max(latest,mp[s[i]]);
            }
            ans = max(ans,i - latest);
            mp[s[i]] = i;
        }
        return ans;
    }
};