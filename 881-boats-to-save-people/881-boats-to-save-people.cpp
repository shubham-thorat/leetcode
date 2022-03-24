class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int i = 0,j = n - 1;
        int count = 0;
        while(i<=j){
            int sum = nums[i] + nums[j];
            if(sum <= limit){
                count++;
                i++;
                j--;
            }
            else if(sum > limit){
                count++;
                j--;
            }
        }
        return count;
    }
};