class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int ans = INT_MIN;
        int lprod = 1,rprod = 1;
        for(int i=0;i<n;i++) {
            lprod = lprod * nums[i];
            rprod = rprod * nums[n-i-1];
            ans = max({ans,lprod,rprod});
            
            if(lprod == 0) lprod = 1;
            if(rprod == 0) rprod = 1;
        }
        
        return ans;
    }
};