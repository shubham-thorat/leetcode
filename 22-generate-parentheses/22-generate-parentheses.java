class Solution {
    public void possibleComb(List<String> result,StringBuilder sb,int open,int close){
        // System.out.println(sb.toString() + " " + open + " " + close + " ");
        if(open == 0 && close == 0){
            result.add(new String(sb.toString()));
            return;
        }
        
        if(open > 0){
            sb.append('(');
            possibleComb(result,sb,open - 1,close);
            sb.deleteCharAt(sb.length() - 1);
        }
        
        if(open < close){
            sb.append(')');
            possibleComb(result,sb,open,close - 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
    public List<String> generateParenthesis(int n) {
        
        List<String> result = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        possibleComb(result,sb,n,n);
        return result;
    }
}