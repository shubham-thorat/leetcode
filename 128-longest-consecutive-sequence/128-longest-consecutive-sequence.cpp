class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) {
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int longestSequence = 1,current = 1;
        
        for(int i=1;i<nums.size();i++) {
            int val = nums[i] - nums[i-1];
            if(val == 1 || val == 0) {
                current += val;
            }    
            else {
                current = 1;
            }
            longestSequence = max(longestSequence,current);
        }
        return longestSequence;
    }
};