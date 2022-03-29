typedef pair<int,int> p32;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<p32,vector<p32>,greater<p32>> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size() > k) pq.pop();
        }
        
        vector<pair<int,int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(),ans.end(),[&](p32 a,p32 b){
            return a.second < b.second;
        });
        vector<int> res;
        for(auto &e:ans){
            res.push_back(e.first);
        }
        return res;
    }
};