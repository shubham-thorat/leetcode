class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0,ans = INT_MAX,j = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            
            while(j < nums.size() && sum >= target){
                ans = min(ans,i-j + 1);
                sum = sum - nums[j];
                j++;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};