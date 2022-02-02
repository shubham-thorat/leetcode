class Solution {
    String isPalidrome(String s,int l,int r){
        while(l>=0 && r < s.length()){
            if(s.charAt(l) != s.charAt(r)){
                break;
            }    
            l--;
            r++;
        }
        return s.substring(l+1,r);
    }
    public String longestPalindrome(String s) {
        String str = "";
        for(int i=0;i<s.length();i++){   
            String opt1 = isPalidrome(s,i,i);
            if(str.length() < opt1.length()){
                str = opt1;
            }
            String opt2 = isPalidrome(s,i,i+1);
            if(str.length() < opt2.length()){
                str = opt2;
            }
        }
        return str;
    
    }
}