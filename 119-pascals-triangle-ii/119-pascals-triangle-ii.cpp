class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long n = 1;
        vector<int> ans;
        long long size = rowIndex + 1;
        for(int i=0;i<(int)size;i++){
            ans.push_back(n);
            n = ((n * (size - i - 1))/(i+1));
        }
        return ans;
    }
};