class Solution {
    public List<Integer> partitionLabels(String s) {
        
        int alpha[] = new int[26];
        
        for(int i=0;i<s.length();i++){
            alpha[s.charAt(i) - 'a'] = i;
        }
        
        List<Integer> list = new ArrayList<Integer>();
        int maxvalue = -1;
        int prev = -1;
        for(int i=0;i<s.length();i++){
            maxvalue = Math.max(maxvalue,alpha[s.charAt(i) - 'a']);
            
            if(i == maxvalue){
                list.add(i - prev);
                prev = i;
            }
        }
        
        return list;
    }
}