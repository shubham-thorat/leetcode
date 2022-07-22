class Solution {
public:
    int lower_bound(vector<int> &nums,int target) {
        int low = 0,high = nums.size() - 1;
        
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
        // if(low < nums.size() && nums[low] == target ) return low;
        // return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1,-1};
        int l = lower_bound(nums,target);
        if(l == nums.size() || nums[l] != target) return {-1,-1};
        
        int r = lower_bound(nums,target + 1) - 1;
        
        return {l,r};
    }
};