class Solution {
public:
    bool helper(string s1,string s2) {
        
        int i = 0,j = 0;
        while(i < s1.length() && j < s2.length()) {
            if(s1[i] == s2[j]) {
                i += 1;
                j += 1;
            }
            else {
                j += 1;
            }
        }
        return (i == s1.length());
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        
        for(auto &e:words) mp[e]++;
        
        int ans = 0;
        for(auto &e:mp) {
            if(helper(e.first,s)) {
                ans += e.second;
            }
        }
        return ans;
    }
};