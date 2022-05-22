class Solution {
    public String longestPalindrome(String s) {
        
        int strLen = s.length();
        if(strLen == 0) return "";
        int ans = 1,lidx = 0,ridx = 0;
        for(int i=0;i<strLen;i++) {
            int lPtr = i,rPtr = i;
            
            while(lPtr >=0 && rPtr < strLen) {
                if(s.charAt(lPtr) != s.charAt(rPtr)) {
                   
                    break;
                }
                lPtr--;
                rPtr++;
            }
            
             if(ans < (rPtr-lPtr - 1)) {
                lidx = lPtr + 1;
                ridx = rPtr - 1;
                ans = rPtr - lPtr - 1;
            } 
        }
        
        for(int i=0;i<strLen-1;i++) {
            int lPtr = i,rPtr = i + 1;
            
            while(lPtr >=0 && rPtr < strLen) {
                if(s.charAt(lPtr) != s.charAt(rPtr)) {     
                    break;
                }
                lPtr--;
                rPtr++;
            }
            if(ans < (rPtr-lPtr - 1)) {
                lidx = lPtr + 1;
                ridx = rPtr - 1;
                ans = rPtr - lPtr - 1;
            }
        }
        
        return s.substring(lidx,ridx + 1);
    }
}