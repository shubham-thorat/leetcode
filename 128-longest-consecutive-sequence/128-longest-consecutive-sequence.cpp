class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        
        for(auto e:nums) mp.insert(e);
        int ans = 0;
        for(auto e:nums){
            if(mp.find(e - 1) == mp.end()){
                int start = e;
                int count = 0;
                while(mp.find(start) != mp.end()){
                    count++;
                    start++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};