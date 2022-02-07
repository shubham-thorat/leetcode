class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int inf = Integer.MAX_VALUE;
        int n = triangle.size();
        int ans = inf;
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle.get(i).size();j++){
                int opt1 = j > 0 ? triangle.get(i-1).get(j - 1) : inf; 
                int opt2 = j < triangle.get(i-1).size() ? triangle.get(i-1).get(j) : inf;
                
                triangle.get(i).set(j,triangle.get(i).get(j) +  Math.min(opt1,opt2));
            }
        }
        
        for(int i=0;i<triangle.get(n-1).size();i++){
            ans = Math.min(ans,triangle.get(n-1).get(i));
        }
        
        return ans;
    }
}