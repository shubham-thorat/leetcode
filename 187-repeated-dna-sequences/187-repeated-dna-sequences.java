class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashSet<String> freq = new HashSet<>();
        
        HashSet<String> list = new HashSet<>();
        for(int i=0;i + 10 <= s.length();i++){
            String str = s.substring(i,i+10);
            
            if(freq.contains(str)){
                list.add(str);
            }
            else {
                freq.add(str);
            }
        }
        List<String> ans = new ArrayList<>();
        for(String t:list){
            ans.add(t);
        }
        return ans;
    }
}

// "A A A A A A A A A A A"
//  0 1 2 3 4 5 6 7 8 9 10