class Solution {
public:
    void extendPalindrome(string s,int l,int r,int &count) {
        
        while(l>=0 && r < s.length()) {
            if(s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
            else break;
        }
    }
    int countSubstrings(string s) {
         if (s.length() == 0) return 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) { // i is the mid point
            extendPalindrome(s, i, i,count); // odd length;
            extendPalindrome(s, i, i + 1,count); // even length
        }
        
        return count;
    }
};