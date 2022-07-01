class Solution {
public:
    int jump(vector<int>& nums) {
        int mn = 0,mx = 0;
        int n = nums.size();
        
        int step = 0,index = 0;
        while(mx < (n-1)) {
            
            for(int i=index;i<n;i++) {
                if((i + nums[i] > mx) && i <= mn) {
                    mx = i + nums[i];
                    index = i;
                }
                if(i > mn) break;
            }
            
            step++;
            mn = mx;
        }
        return step;
    }
};