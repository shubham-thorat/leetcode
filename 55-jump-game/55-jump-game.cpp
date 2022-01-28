class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return true;
        if(nums[0] == 0) return 0;
        
        int maxJump = nums[0];
        
        for(int i=1;i<n;i++){
            
            if(i > maxJump){
                return false;
            }
            maxJump = max(maxJump,i + nums[i]);            
        }
        return true;
    }
};