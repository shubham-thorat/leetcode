class Solution {
public:
    
    int fibUtil(int n,vector<int> &memo) {
        if(n == 0 || n == 1) {
            return n;
        }
        if(memo[n] != -1) {
            return memo[n];
        }
        
        return memo[n] = fibUtil(n-1,memo) + fibUtil(n-2,memo);
    }
    int fib(int n) {
        vector<int> memo(n+1,-1);
        
        return fibUtil(n,memo);
    }
};