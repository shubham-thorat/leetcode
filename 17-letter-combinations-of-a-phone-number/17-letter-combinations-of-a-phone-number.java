class Solution {
    private void possibleComb(HashMap<Integer,String> numberletter,String digits,int index,List<String> result,StringBuilder sb){
        if(index == digits.length()){
            if(sb.length() != 0)
                result.add(sb.toString());
            return;
        }
        
        int digit = digits.charAt(index) - '0';
        
        String str = numberletter.get(digit);
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            sb.append(ch);
            possibleComb(numberletter,digits,index+1,result,sb);
            sb.deleteCharAt(index);
        }
    }
    public List<String> letterCombinations(String digits) {
        HashMap<Integer,String> numberletter = new HashMap<>();
        
        numberletter.put(2,"abc");
        numberletter.put(3,"def");
        numberletter.put(4,"ghi");
        numberletter.put(5,"jkl");
        numberletter.put(6,"mno");
        numberletter.put(7,"pqrs");
        numberletter.put(8,"tuv");
        numberletter.put(9,"wxyz");
        
        List<String> result = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        possibleComb(numberletter,digits,0,result,sb);
        return result;
    }
}