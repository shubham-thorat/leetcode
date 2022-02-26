class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto &e:nums){
            mp[e] += 1;
            if(mp[e] == 2) return e;
        }
        return -1;
    }
};