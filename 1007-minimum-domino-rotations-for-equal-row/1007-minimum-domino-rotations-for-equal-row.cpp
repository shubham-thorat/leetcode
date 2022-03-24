class Solution {
public:
    int solve(vector<int> &tops,vector<int> &bottoms,unordered_set<int> &st) {
        int ans = INT_MAX;
        int n = tops.size();
        for(auto &e:st){
            bool istrue = true;
            int count = 0;
            for(int i=0;i<n;i++){
                if(tops[i] == e) continue;
                if(bottoms[i] == e) count++;
                else {
                    istrue = false;
                    break;
                }
            }
            if(istrue){
                ans = min(ans,count);
            }
        }
        return ans;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       unordered_set<int> st1,st2;
        
        for(auto &e:tops) st1.insert(e);
        for(auto &e:bottoms) st2.insert(e);
        
        int opt1 = solve(tops,bottoms,st1);
        int opt2 = solve(bottoms,tops,st2);
        
        if(opt1 == INT_MAX && opt2 == INT_MAX) return -1;
        else return min(opt1,opt2);
        
     }
};