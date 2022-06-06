class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int prevNonZero = 0;
        
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                swap(nums[prevNonZero],nums[i]);
                prevNonZero += 1;
            }
        }
        
        
    }
};