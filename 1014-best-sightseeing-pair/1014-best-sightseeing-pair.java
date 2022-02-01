class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        if(n == 0 || n == 1) return 0;
        int maxendright = values[n-1] - (n-1);
        int maxgain = 0;
        for(int i=n-2;i>=0;i--){
            maxgain = Math.max(maxgain,values[i] + i + maxendright);
            
            maxendright = Math.max(maxendright,values[i] - i);
        }
        return maxgain;
    }
}