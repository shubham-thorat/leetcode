class Solution {
public:
    void merge(vector<int> &nums,int l,int m,int r,int &ans){
        int j = m + 1;
        for(int i=l;i<=m;i++){
            while(j <= r && nums[i] > (2 * 1LL * nums[j]) ){
                j++;
            }
            ans += (j - (m + 1));
        }
        
        sort(nums.begin() + l, nums.begin() + r + 1);
    }
    void helper(vector<int> &nums,int l,int r,int &ans){
        if(l < r){
            int m = l + (r-l)/2;
            
            helper(nums,l,m,ans);
            helper(nums,m+1,r,ans);
            merge(nums,l,m,r,ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        helper(nums,0,nums.size() - 1,ans);
        return ans;
    }
};