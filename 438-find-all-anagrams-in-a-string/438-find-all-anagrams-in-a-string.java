class Solution {
    boolean check(int nums1[],int nums2[]){
        for(int i=0;i<26;i++){
            if(nums1[i] != nums2[i]){
                return false;
            }
        }
        return true;
    }
    public List<Integer> findAnagrams(String s, String p) {
        
        List<Integer> ans = new ArrayList<Integer>();
        int smap[] = new int[26],pmap[] = new int[26];
        
        if(p.length() > s.length()) return ans;
        
        int n = p.length();
        for(int i=0;i<p.length();i++){
            smap[s.charAt(i) - 'a'] += 1;
            pmap[p.charAt(i) - 'a'] += 1;
        }
        
        if(check(smap,pmap)){
            ans.add(0);
        }
        
        for(int i=n;i<s.length();i++){
            smap[s.charAt(i) - 'a'] += 1;
            smap[s.charAt(i - n) - 'a'] -= 1;
            
            if(check(smap,pmap)){
                ans.add(i - n + 1);
            }
        }
        return ans;
    }
}