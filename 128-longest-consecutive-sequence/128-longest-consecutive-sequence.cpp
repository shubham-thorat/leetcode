class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        for(auto &e:nums) st.insert(e);
        
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            
            if(st.find(nums[i] - 1) == st.end()) {
                int val = nums[i];
                while(st.find(val) != st.end()) {
                    val += 1;
                }
                count = max(count,val - nums[i]);
            }
        }
        return count;
    }
};

// 1 2 3 4 100 200
   