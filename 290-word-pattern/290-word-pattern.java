class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<Character,String> exists = new HashMap<>();
        HashMap<String,Character> exists2 = new HashMap<>();
        
        String words[] = s.split(" ");
        
        if(words.length != pattern.length()) return false;
        
        for(int i=0;i<pattern.length();i++){
            char ch = pattern.charAt(i);
            if(exists.containsKey(ch)){
                if(!exists.get(ch).equals(words[i])){
                    return false;   
                }
            }
            else {
                exists.put(ch,words[i]);
            }
            
            if(exists2.containsKey(words[i])){
                if(!(exists2.get(words[i]) == ch)){
                    return false;
                }
            }
            else {
                exists2.put(words[i],ch);
            }
        }
      
        return true;
    }
}