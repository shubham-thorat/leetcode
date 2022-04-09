class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long long int> v;
        v.push_back(0);
        for(long long int i=1;i*i<=c;i++){
            v.push_back(i * i);
        }
        
    long long int l =0,r = v.size() - 1;
        
        while(l <= r){
            long long int sum = v[l] + v[r];
            
            if(sum == c) return true;
            else if(sum > c) {
                r--;
            }
            else {
                l++;
            }
        }
        return false;
    }
};