class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        int k = 3;
        int count1 = 0,ele1,count2 = 0,ele2;
        
        for(int i=0;i<n;i++){
           if(ele1 == nums[i]){
               count1 += 1;
            }
            else if(ele2 == nums[i]){
                count2 += 1;
            }
            else {
                if(count1 == 0){
                    ele1 = nums[i];
                    count1 = 1;
                }
                else if(count2 == 0){
                    ele2 = nums[i];
                    count2 = 1;
                }
                else {
                    count1--;
                    count2--;
                }
            }
        }
        count1 = 0,count2 = 0;
        
        for(auto e:nums){
            if(ele1 == e) count1 += 1;
            else if(ele2 == e) count2 += 1;
        }
        vector<int> ans;
        if(count1 > (n/k)) ans.push_back(ele1);
        if(count2 > (n/k)) ans.push_back(ele2);
        return ans;
    }
};