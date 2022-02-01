class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        HashMap<String,ArrayList<String>> map = new HashMap<>();
        
        for(String str:strs){
            char ch[] = str.toCharArray();
            
            Arrays.sort(ch);
            
            String s = String.valueOf(ch);
            
            if(map.containsKey(s)){
                map.get(s).add(str);
            }
            else {
                map.put(s,new ArrayList<String>(Arrays.asList(str)));
            }
        }
        
        List<List<String>>  ans = new ArrayList<List<String>>();
        
        for(Map.Entry<String,ArrayList<String>> entry:map.entrySet()){
            ans.add(entry.getValue());
        }
        return ans;
    }
}