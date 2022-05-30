class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n = nums.size(),ans = 0;
        
        st.push({n-1,0});
        for(int i=n-2;i>=0;i--) {
            int count = 0;
            while(!st.empty() && nums[st.top().first] < nums[i]) {
                count = max(count + 1,st.top().second);
                st.pop();
            }
            ans = max(ans,count);
            st.push({i,count});
        }
        return ans;
    }
};