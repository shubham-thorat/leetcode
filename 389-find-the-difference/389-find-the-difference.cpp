class Solution {
public:
    char findTheDifference(string s, string t) {
        int charCount[26] = {0};
        
        for(char ch:s) {
            charCount[ch - 'a'] += 1;
        }
        
        for(char ch:t) {
            charCount[ch - 'a'] -= 1;
        }
        
        for(int i=0;i<26;i++) {
            if(charCount[i] < 0) return ('a' + i);
        }
        return 'a';
    }
};