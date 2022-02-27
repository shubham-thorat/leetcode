class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        int result = 0;
        while(num > 0){
            if(result > (INT_MAX/10)) return 0;
            if(result < (INT_MIN/10)) return 0;
            result = result * 10 + (num%10);
            num = num/10;
        }
        if(x < 0) return -1 * result;
        return result;
    }
};