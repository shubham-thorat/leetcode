class Solution {
public:
    int partition(vector<int> &nums,int lo,int hi) {
        int pivot = nums[hi];
        int i = lo,j = lo;
        
        
        while(j < hi) {
            if(nums[j] < pivot) {
                swap(nums[j],nums[i]);
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        
        swap(nums[hi],nums[i]);
        return i;
    }
    int solve(vector<int> &nums,int lo,int hi,int k) {
        int n = nums.size();
        if(lo <= hi) {
            int p = partition(nums,lo,hi);
            
            if((hi-p + 1) == k) return nums[p];
            
            if((hi-p + 1) < k) return solve(nums,lo,p-1,k - (hi-p + 1));
            else return solve(nums,p+1,hi,k);
        }
        return 9999999;
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        return solve(nums,0,nums.size() - 1,k);
    }
};