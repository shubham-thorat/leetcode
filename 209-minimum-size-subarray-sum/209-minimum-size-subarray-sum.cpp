class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {        
        int n = nums.size();
        for(int i=1;i<n;i++) {
            nums[i] += nums[i-1];
        }
        int i1 = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int ans = i1 + 1;
        for(int i=0;i<n;i++) {
            int curr = nums[i] + target;
               
            int idx = lower_bound(nums.begin() + i,nums.end(),curr) - nums.begin();
            // cout << idx << " " << curr<<endl;
            if(idx < n ){
                ans = min(ans,idx-i);
            }
        }
        return ans > n ? 0 : ans;
    }
};