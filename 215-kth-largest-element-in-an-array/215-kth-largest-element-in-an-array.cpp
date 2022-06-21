class Solution {
public:
    int partition(vector<int> &nums,int low,int high) {
        int pivot = nums[low];
        int i = high,j = high;
        
        while(i > low) {
            if(nums[i] < pivot) {
                swap(nums[i],nums[j]);
                i--;
                j--;
            }
            else {
                i--;
            }
        }
        swap(nums[low],nums[j]);
        return j;
    }
    int solve(vector<int> &nums,int low,int high,int k) {
        
        if(low <= high) {
            
            int index = partition(nums,low,high);
            int sz = index - low + 1;
            if(sz == k) {
                return nums[index];
            }
            else if(sz < k) {
                return solve(nums,index + 1,high,k - sz);
            }
            else {
                return solve(nums,low,index - 1,k);
            }
        }
        else {
            return INT_MAX;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        return solve(nums,0,nums.size() - 1,k);
    }
};