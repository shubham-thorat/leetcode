class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        int charcount[26] = {0};
        
        for(char ch:s) {
            charcount[ch - 'a'] += 1;
        }
        
        for(char ch:t) {
            charcount[ch - 'a'] -= 1;
            
            if(charcount[ch-'a'] < 0) return false;
        }
        return true;
    }
};