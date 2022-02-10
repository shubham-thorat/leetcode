typedef long long ll;
class Solution {
public:
    bool asteroidsDestroyed(int sum, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll mass = sum;
        for(int val:nums){
           if(mass < val) return false;
            mass += val;
        }
        return true;
    }
};