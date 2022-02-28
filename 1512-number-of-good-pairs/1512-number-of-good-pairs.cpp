class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count = 0;
        for(auto &e:nums) {
            if(mp.find(e) != mp.end()){
                count += mp[e];
            }
            mp[e] += 1;
        }
        return count;
    }
};