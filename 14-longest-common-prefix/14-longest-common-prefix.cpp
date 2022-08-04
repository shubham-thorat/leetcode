class Solution {
public:
    int combine(string s1,string s2,int len) {
        int i = 0;
        while(i < len && i<s1.length() && i < s2.length() && s1[i] == s2[i]) {
            i++;
        }
        return i;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].length();
        
        for(int i=1;i<strs.size();i++) {
            len = min(len,combine(strs[i],strs[i-1],len));
        }
        return strs[0].substr(0,len);
    }
};