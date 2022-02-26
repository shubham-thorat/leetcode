class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int j = i;
            
            while((j + 1) != nums[j]){
                if(nums[nums[j] - 1] == nums[j]) break;
                
                swap(nums[j],nums[nums[j] - 1]);
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(i + 1 != nums[i]) return nums[i];
        }
        return -1;
    }
};