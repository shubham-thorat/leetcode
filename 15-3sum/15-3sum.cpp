class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1;i>=2;i--) {
            int low = 0,high = i - 1;
            
            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                
                if(sum == 0) {
                    ans.insert({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                  
                    // while(low > 0 && nums[low] == nums[low-1]) low++;
                    // while(high < n-1 && nums[high] == nums[high + 1]) high--;
                    
                }
                else if(sum > 0) {
                    high--;
                }
                else {
                    low++;
                }
            }
        }
        
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};