class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> st;
        for(auto &e:nums) st[e] += 1;
        
        vector<int> ans;
        for(auto &e:nums){
            if(st[e] == 1 && st.find(e-1) == st.end() && st.find(e + 1) == st.end()){
                ans.push_back(e);
            }
        }
        return ans;
    }
};