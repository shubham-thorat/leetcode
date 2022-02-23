class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int val=nums[i]+nums[l]+nums[r];
                if(abs(val-target)<abs(sum-target))
                {
                    sum=val;
                }
                else if(val<target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
                
            }
        }
        return sum;
    }
};