class Solution {
    public String minRemoveToMakeValid(String s) {
        int bracket = 0;
        HashSet<Integer> extra = new HashSet<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch == ')'){
                bracket -= 1;
                if(bracket < 0){
                    extra.add(i);
                    bracket = 0;
                }
            }
            else if(ch == '('){
                bracket += 1;
            }
        }
        
        if(bracket > 0){
            for(int i=s.length()-1;i>=0 && bracket > 0;i--){
                if(s.charAt(i) == '('){
                    bracket--;
                    extra.add(i);
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(!extra.contains(i)){
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}