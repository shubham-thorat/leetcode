class Solution {
public:
    int trap(vector<int>& height) {
        
        int sum = 0;
        int n = height.size();
        vector<int> leftMax(n,0),rightMax(n,0);
        for(int i=0;i<n;i++) {
            leftMax[i] = max((i > 0 ? leftMax[i-1] : 0),height[i]);
            
            rightMax[n-i-1] = max((n-i < n ? rightMax[n-i] : 0),height[n-i-1]);
        }
        for(int i=1;i<height.size()-1;i++) {
            int j = i;
            // int leftMax = 0,rightMax = 0;
            
            sum += min(leftMax[i],rightMax[i]) - height[i];
        }
        return sum;
    }
};