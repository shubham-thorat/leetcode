class Solution {
public:
    bool isvowel(char ch) {
        return (ch == 'a' ||ch == 'A'|| ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    string reverseVowels(string s) {
        
        int low = 0,high = s.length() - 1;
        
        while(low < high) {
            while(low < high && !isvowel(s[low])) {
                low += 1;
            }
            
            while(low < high && !isvowel(s[high])) {
                high -= 1;
            }
            
            if(low <= high) {
                swap(s[low],s[high]);
                low += 1;
                high -= 1;
            }
        }
        
        return s;
    }
};