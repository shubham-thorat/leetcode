class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ele;
        int count = 0;
        
        for(int i=0;i<n;i++){
            if(ele == nums[i]){
                count++;
            }
            else {
                if(count == 0){
                    ele = nums[i];
                    count = 1;
                }
                else count--;
            }
        }
        return ele;
    }
};