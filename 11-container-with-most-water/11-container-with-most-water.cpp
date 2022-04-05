class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,j = height.size() - 1;
        int len = height.size() - 1;
        int ans = 0;
        while(i <= j){
            ans = max(ans,len * min(height[i],height[j]));
            
            if(height[i] <= height[j]){
                i++;
            }
            else {
                j--;
            }
            len--;
        }
        
        return ans;
    }
};