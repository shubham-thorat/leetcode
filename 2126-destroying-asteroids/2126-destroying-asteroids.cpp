typedef long long ll;
class Solution {
public:
    bool asteroidsDestroyed(int sum, vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto e:nums){
            pq.push(e);
        }
        ll mass = sum;
        while(!pq.empty()){
            int val = pq.top(); pq.pop();
            if(mass >= val){
                mass += val;
            }
            else mass -= val;
        }
        
        return (mass >=0);
    }
};