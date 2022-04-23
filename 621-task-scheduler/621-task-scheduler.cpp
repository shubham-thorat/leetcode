class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        
        for(char ch:tasks) mp[ch] += 1;
        
        priority_queue<int> pq;
        for(auto &e:mp) pq.push(e.second);
        int result = 0;
        while(!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for(int i=0;i<=n;i++){
                if(!pq.empty()) {
                    time += 1;
                    tmp.push_back(pq.top() - 1);
                    pq.pop();
                }
            }
            
            for(auto &e:tmp) {
                if(e) pq.push(e);
            }
            
            result += pq.empty() ? time : n + 1;
        }
        return result;
    }
};