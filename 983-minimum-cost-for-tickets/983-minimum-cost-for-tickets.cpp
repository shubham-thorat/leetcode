class Solution {
public:
    int helper(int ith_day,unordered_set<int> &days,vector<int> &costs,vector<int> &memo){
        
        if(ith_day > 365) return 0;
        
        if(memo[ith_day] != -1){
            return memo[ith_day];
        }
        
        if(days.find(ith_day) == days.end()){
            return helper(ith_day + 1,days,costs,memo);
        }
        
        int opt1 = helper(ith_day + 1,days,costs,memo) + costs[0];
        int opt2 = helper(ith_day + 7,days,costs,memo) + costs[1];
        int opt3 = helper(ith_day + 30,days,costs,memo) + costs[2];
        
        return memo[ith_day] = min({opt1,opt2,opt3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        unordered_set<int> st;
        for(auto e:days){
            st.insert(e);
        }
        vector<int> memo(366,-1);
        
        return helper(1,st,costs,memo);
    }
};