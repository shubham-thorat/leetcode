class Solution {
public:
    int inf = 1e9;
    
    vector<vector<vector<int>>> memo;
    int solve(vector<int> &houses,int lc,int idx,int target,vector<vector<int>>& cost) {
        int m = cost.size();
        int n = cost[0].size();
        if(idx == m && target == 0) {
            return 0;
        }
        
        if(idx == m || target < 0) {
            return inf;
        }
        if(memo[lc][idx][target] != -1) {
            return memo[lc][idx][target];
        }
        
        if(houses[idx] != 0) {
            if(houses[idx] == lc) {
                return memo[lc][idx][target] = solve(houses,lc,idx + 1,target,cost);
            }
            else {
                return memo[lc][idx][target] = solve(houses,houses[idx],idx + 1,target - 1,cost);
            }
        }
        
        int ans = inf;
        for(int i=0;i<n;i++) {
            int newcolor = i + 1;
            int temp;
            if(newcolor == lc) {
                temp = solve(houses,lc,idx + 1,target,cost) + cost[idx][i];
            }
            else {
                temp = solve(houses,newcolor,idx + 1,target - 1,cost) + cost[idx][i];
            }
            ans = min(ans,temp);
        }
        return memo[lc][idx][target] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
          memo.resize(n + 1,vector<vector<int>>(m + 1,vector<int>(target + 1,-1)));
        int ans = solve(houses,0,0,target,cost);
        return (ans >= inf ? -1 : ans);
    }
};