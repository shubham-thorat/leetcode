class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1;i>=2;i--) {
            int low = 0,high = i - 1;
            if(i < n-1 && nums[i] == nums[i+1]) continue;
            
            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                
                if(sum == 0) {
                    ans.push_back({nums[i],nums[low],nums[high]});
                   int a = nums[low];
                    int b = nums[high];
                    while(low < high && nums[low] == a) {
                       low++;
                   }
                    
                    while(low < high && nums[high] == b) {
                        high--;
                    }
                }
                else if(sum > 0) {
                    high--;
                }
                else {
                    low++;
                }
            }
        }
        return ans;
        // return vector<vector<int>>(ans.begin(),ans.end());
    }
};