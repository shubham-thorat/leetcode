class Solution {
public:
    int countOdds(int low, int high) {
        
        if(high%2 == 0) high--;
        if(low%2 != 0) low--;
        
        return (high + 1)/2 - low/2;
    }
};