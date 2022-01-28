class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](vector<int> &a,vector<int> &b){
           if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int left = 0,right = 1;
        int n = nums.size();
        int count = 0;
        while(right < n){
            
            if(nums[left][1] <= nums[right][0]){
                left = right;
                right += 1;
            }
            else if(nums[right][1] > nums[left][1]){
                right += 1;
                count++;
            }
            else {
                left = right;
                right += 1;
                count++;
            }
        }
        return count;
    }
};