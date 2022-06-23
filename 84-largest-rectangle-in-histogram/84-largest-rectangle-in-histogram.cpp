class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;
        
        
        int n = nums.size();
        if(n == 0) return 0;
        int maxA =0;
        for(int i=0;i<=n;i++) {
            
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])) {
                
                int currHeight = nums[st.top()];
                st.pop();
                
                int width;
                
                if(st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }
                
                maxA = max(maxA,width * currHeight);
            }
            st.push(i);
        }
        return maxA;
    }
};