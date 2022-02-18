class Solution {
     public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        
        for(int i=0;i<num.length();i++){
            char ch = num.charAt(i);
            while(!st.isEmpty() && k > 0 && st.peek() > ch){
                st.pop();
                k--;
            }
            if(st.isEmpty() && ch == '0'){
                continue;
            }
            st.push(ch);
        }
        while(k > 0){
            if(!st.isEmpty()){
                st.pop();
            }
            k--;
        }
        
        StringBuilder sb = new StringBuilder("");
        while(!st.isEmpty()){
            sb.append(st.pop());
        }
        
        // int i = sb.length();
        // while(i > 0){
        //     if(sb.charAt(i-1) == '0'){
        //         sb.deleteCharAt(i-1);
        //         i--;
        //     }
        //     else {
        //         break;
        //     }
        // }
        if(sb.length() == 0) return "0";
        return sb.reverse().toString();
    }
}