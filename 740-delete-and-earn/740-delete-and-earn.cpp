class Solution {
public:
   
    int deleteAndEarn(vector<int>& nums) {
       unordered_map<int,int> sum;
        
        int maxvalue = 0;
        for(auto e:nums){
            sum[e] += e;
            maxvalue = max(maxvalue,e);
        }
        
        unordered_map<int,int> dp;
        dp[1] = sum[1];
        dp[2] = max(sum[1],sum[2]);
        
        for(int i=3;i<=maxvalue;i++){
            dp[i] = max(dp[i-2] + sum[i],dp[i-1]);
        }
        
        return max(dp[maxvalue],dp[maxvalue - 1]);
    }
};