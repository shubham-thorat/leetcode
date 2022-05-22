class Solution {
    int expand(String s,int l,int r) {
        
        while(l >=0 && r < s.length()) {
            if(s.charAt(l) != s.charAt(r)) {
                break;
            }
            l--;
            r++;
        }
        
        return (r-l-1);
    }
    public String longestPalindrome(String s) {
        
        int strlen = s.length();
        int ans = 0,left = -1;
        for(int i=0;i<strlen;i++) {
            int len1 = expand(s,i,i);
            int len2 = expand(s,i,i + 1);
            
            int len = Math.max(len1,len2);
            
            if(len > ans) {
                ans = len;
                left = i - (len-1)/2;    
            }
        }
        return s.substring(left,left + ans);
    }
}