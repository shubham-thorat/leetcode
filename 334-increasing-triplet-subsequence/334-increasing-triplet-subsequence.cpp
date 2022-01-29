class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX,second = first;
        
        for(int i=0;i<n;i++){
            if(nums[i] <= first){
                first = nums[i];
            }
            else if(nums[i] <= second){
                second = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};