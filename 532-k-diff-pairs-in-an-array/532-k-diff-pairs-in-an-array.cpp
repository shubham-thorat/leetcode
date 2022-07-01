class Solution {
public:
    void Insert(set<pair<int,int>> &st,int a,int b) {
        st.insert({min(a,b),max(a,b)});    
    }
    int findPairs(vector<int>& nums, int k) {
    
        set<pair<int,int>> st;
        unordered_map<int,int> mp;
        
        for(auto &e:nums) {
            if(mp.find(e - k) != mp.end()) {
                Insert(st,e,e-k);
            }
            
            if(mp.find(e + k) != mp.end()) {
                Insert(st,e,e + k);
            }
            mp[e] += 1;
        }
        return st.size();
    }
};