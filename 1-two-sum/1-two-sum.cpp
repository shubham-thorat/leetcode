class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            int e = nums[i];
            if(mp.find(target - e) != mp.end()){
                return {i,mp[target - e]};
            }
            mp[e] = i;
        }
        return {};
    }
};