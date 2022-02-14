class Solution {
    int helper(ArrayList<Integer> list,int n,int dp[]){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int ans = (int)(1e5);
        for(int i=list.size()-1;i>=0;i--){
            if(n >= list.get(i)){
                int opt = helper(list,n - list.get(i),dp);
                ans = Math.min(ans,opt);
            }
        }
        return dp[n] = ans + 1;
        
    }
    public int numSquares(int n) {
        int i = 1;
        ArrayList<Integer> sq = new ArrayList<>();
        
        while(i * i <= n){
            sq.add(i*i);
            i += 1;
        }
        int dp[] = new int[n+1];
        Arrays.fill(dp,-1);
        return helper(sq,n,dp);
    }
}