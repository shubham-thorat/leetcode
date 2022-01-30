class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int min_so_far = nums[0],max_so_far = nums[0];
        int min_curr = nums[0],max_curr = nums[0];
        int sum = nums[0];
        
        
        for(int i=1;i<nums.size();i++){
            min_curr = min(nums[i],min_curr + nums[i]);
            sum += nums[i];    
            min_so_far = min(min_so_far,min_curr);
            
            max_curr = max(nums[i],max_curr + nums[i]);
            max_so_far = max(max_so_far,max_curr);
        }
        if(sum == min_so_far) return max_so_far;
        
        return max((sum - min_so_far),max_so_far);
    }
};