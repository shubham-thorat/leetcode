class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        
        if(n == 0) return 1;
        if(n == 1) return s.charAt(0) == '0' ? 0: 1;
        if(s.charAt(0) == '0') return 0;
       int last = 1;
        int prevlast = 1;
        for(int i=2;i<=n;i++){
            int prevone = s.charAt(i-1) - '0';
            int prevtwo = (s.charAt(i-2) - '0')*10 + prevone;
            int curr = 0;
            if(prevone != 0) curr += last;
            if(prevtwo == 0) return 0;
            
            if(prevone != prevtwo && prevtwo <= 26){
                curr += prevlast;
            }
            
            prevlast = last;
            last = curr;
        }
        
        return last;
    }
}