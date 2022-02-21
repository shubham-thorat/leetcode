class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int count = 1;
        int ele = nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i] == ele){
                count++;
            }
            else {
                count--;
            }
            
            if(count < 0){
                count = 1;
                ele = nums[i];
            }
        }
        return ele;
    }
};