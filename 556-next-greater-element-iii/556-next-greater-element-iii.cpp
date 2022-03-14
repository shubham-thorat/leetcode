class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(),str.end());
        long long val = 0;
        for(int i=0;i<str.length();i++){
            val = val * 10 + (str[i] - '0');
           if(val > INT_MAX) return -1; 
            
        }
        if(val <= n) return -1;
        return val;
    }
};