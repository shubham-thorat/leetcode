class Solution {
public:
    int uniquePaths(int m, int n) {
        //(m+n-2)C(n-1)
        
        long long result = 1;
        long long val = m + n - 2;
        for(long long i=1;i<=min(n-1,m-1);i++){
            result = ((result * val)/i);
            val--;
        }
        return result;
    }
};