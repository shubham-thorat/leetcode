class Solution {
public:
    int findPivot(vector<int> nums) {
        
        int low = 0,high = nums.size() - 1;
        
        while(low <= high) {
            int mid = (low + high)>>1;
            
            if(mid < high && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if(low < mid && nums[mid - 1] > nums[mid]) {
                return mid - 1;
            }
            else if(nums[low] >= nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums,int val,int low,int high) {
         // int low = 0,high = nums.size() - 1;
        
        while(low <= high) {
            int mid = (low + high)>>1;
            
            if(nums[mid] == val) return mid;
            
            if(nums[mid] > val) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int pidx = findPivot(nums);
        int l = search(nums,target,0,pidx);
        if(l != -1) return l;
        int r = search(nums,target,pidx + 1,nums.size() - 1);
        return r;
    }
};