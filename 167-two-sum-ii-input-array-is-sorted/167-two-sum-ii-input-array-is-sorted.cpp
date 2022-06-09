class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int lowptr = 0,highptr = numbers.size() - 1;
        
        
        while(lowptr < highptr) {
            int sum = numbers[lowptr] + numbers[highptr];
            if(sum == target) {
                return {lowptr+1,highptr+1};
            }
            else if(sum > target) {
                highptr--;
            }
            else {
                lowptr++;
            }
        }
        
        return {};
    }
};