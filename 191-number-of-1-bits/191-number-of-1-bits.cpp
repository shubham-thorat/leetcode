class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bitCount = 0;
        while(n > 0) {
            if((n&1) != 0) {
                bitCount += 1; 
            }
            
            // cout << n <<" "<< bitCount << endl;
            
            n = n >> 1;
        }
        return bitCount;
    }
};