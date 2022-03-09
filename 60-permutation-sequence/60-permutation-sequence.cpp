class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        
        string nums = "";
        for(int i=0;i<n;i++) nums.push_back(i + 1 + '0');
        string ans = "";
        vector<int> factorial(n + 1,0);
        factorial[0] = 1;
        for(int i=1;i<=n;i++){
            factorial[i] = factorial[i-1] * i;
        }
        for(int i=0;i<n;i++){
            int fact = factorial[n-i-1];
            int index = (k/fact);
            ans.push_back(nums[index]);
            nums.erase(nums.begin() + index,nums.begin() + index + 1);
            k = k%fact;           
        }
        return ans;
    }
};