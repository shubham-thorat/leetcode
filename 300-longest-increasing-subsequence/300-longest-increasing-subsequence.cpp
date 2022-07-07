class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> lis(n,1);
        int maxlis = 1;
        for(int i=1;i<n;i++) {
            int j = i - 1;
            while(j>=0) {
                if(nums[j] < nums[i]) {
                    lis[i] = max(lis[i],lis[j] + 1);
                }
                j--;
            }
            
            maxlis = max(maxlis,lis[i]);
        }
        int ans = maxlis;
        for(int i=n-1;i>=0;i--) {
            if(lis[i] == maxlis) {
                cout << nums[i] << " ";
                maxlis--;
            }
        } 
        cout << "\n";
        return ans;
        
    }
};