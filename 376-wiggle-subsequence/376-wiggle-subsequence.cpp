class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        vector<int> negative(n,1),positive(n,1);
        int ans = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                int val = nums[i] - nums[j];
                
                if(val > 0) {
                    positive[i] = max(positive[i],negative[j] + 1);
                }
                else if(val < 0){
                    negative[i] = max(negative[i],positive[j] + 1);
                }
            }
            // cout << positive[i] << " " << negative[i] << endl;
            ans = max({ans,positive[i],negative[i]});
        }
        return ans;
    }
};