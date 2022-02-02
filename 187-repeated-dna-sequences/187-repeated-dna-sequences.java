class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
       HashMap<String,Integer> freq = new HashMap<>();
        for(int i=0;i + 10 <= s.length();i++){
            String str = s.substring(i,i+10);
            freq.put(str,freq.getOrDefault(str,0) + 1);
        }
        List<String> ans = new ArrayList<>();
        for(Map.Entry<String,Integer> entry:freq.entrySet()){
            if(entry.getValue() >= 2){
                ans.add(entry.getKey());
            }
        }
        return ans;
    }
}

// "A A A A A A A A A A A"
//  0 1 2 3 4 5 6 7 8 9 10