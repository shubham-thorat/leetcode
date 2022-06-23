class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        
        for(int i=0;i<k-1;i++) {
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int> ans;
        for(int i=k-1;i<nums.size();i++) {
            
            if(!q.empty() && (i - q.front() + 1) > k) {
                q.pop_front();
            }
            
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};