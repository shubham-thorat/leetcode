class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return cost[0];
        int two = cost[0];
        int one = cost[1];
        for(int i=2;i<n;i++){
            int temp = min(one,two) + cost[i];
            two = one;
            one = temp;
        }
        
        return min(one,two);
    }
};