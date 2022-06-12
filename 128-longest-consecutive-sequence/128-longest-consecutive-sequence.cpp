class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        if(nums.size() == 0) return 0;
        int ans = 1,count = 1;
        
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == nums[i-1]) continue;
            
            if(nums[i] - nums[i-1] == 1) {
                count += 1;
            }
            else {
                count = 1;
            }
            // cout << count << " ";
            ans = max(ans,count);
        }
        return ans;
    }
};

// 1 2 3 4 100 200
   