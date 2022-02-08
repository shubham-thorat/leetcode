class Solution {
    HashMap<String,Boolean> memo;
    public boolean canSplit(String s,List<String> wordDict){
        int size = s.length();
        if(size == 0){
            return true;
        }
        if(memo.containsKey(s)){
            return memo.get(s);
        }
        for(int len = 0;len < size;len++){
            String cut = s.substring(len,size);
            if(wordDict.contains(cut)){
                boolean issplitremain = canSplit(s.substring(0,len),wordDict);
                if(issplitremain){
                    memo.put(s,true);
                    return true;
                }
            }
        }
        
        memo.put(s,false);
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        memo = new HashMap<String,Boolean>();
        return canSplit(s,wordDict);
    }
}