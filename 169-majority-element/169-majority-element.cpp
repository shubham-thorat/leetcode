class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int num1 = INT_MIN,cnt1 = 0;
        
        for(auto &e:nums) {
            if(num1 == e) {
                cnt1++;
            }
            else if(cnt1 == 0){
                num1 = e;
                cnt1 = 1;
            }
            else {
                cnt1--;
            }
        }
        
        return num1;
    }
};