class Solution {
public:
    
    int maxScoreUtil(vector<int> &points,int k,int l,int r,vector<vector<int>> &dp) {
        if(l > r) return 0;
        if(k == 0) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int left = maxScoreUtil(points,k-1,l+1,r,dp) + points[l];
        int right = maxScoreUtil(points,k-1,l,r-1,dp) + points[r];
        
        return dp[l][r] = max(left,right);
    }
    int Accumulate(vector<int> &a) {
        int sum = 0;
        for(auto &e:a) sum += e;
        return sum;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = Accumulate(cardPoints);
        if(n <= k) return total;
        
        int sz = n - k;
        int sum = 0, j =0;
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if((i - j + 1) > sz) {
                sum = sum - cardPoints[j];
                j += 1;
            }
            sum += cardPoints[i];
            if(i >= sz-1) {
                ans = max(ans,total - sum);
            }
        }
        return ans;
    }
};