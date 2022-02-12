class Solution {
    public String longestCommonPrefix(String[] strs) {
        int idx = 0;
        int min_length = Integer.MAX_VALUE;
        for(int i=0;i<strs.length;i++){
            min_length = Math.min(min_length,strs[i].length());
        }
        
        for(int i=0;i<min_length;i++){
            for(int j=1;j<strs.length;j++){
                if(strs[j].charAt(i) != strs[j-1].charAt(i)){
                    return strs[j].substring(0,i);
                }
            }
        }
        return strs[0].substring(0,min_length);
    }
}