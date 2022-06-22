class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(auto &e:nums) {
            mp[e] += 1;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto &e:mp) {
            pq.push({e.second,e.first});
            
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};