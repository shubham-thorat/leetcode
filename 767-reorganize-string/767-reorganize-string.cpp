typedef pair<int,char> p32;
class Solution {
public:
   string reorganizeString(string s) {
       unordered_map<char,int> mp;
       for(const auto &ch:s) {
           mp[ch] += 1;
       }
       
       priority_queue<p32> pq;
       
       for(auto &e:mp) {
           pq.push({e.second,e.first});
       }
       
       string ans = "";
       while(!pq.empty()) {
           auto [cnt,ch] = pq.top(); pq.pop();
           
           if(cnt > 1) {
               if(pq.empty()) return "";
               else {
                   ans.push_back(ch);
                   auto [cnt2,ch2] = pq.top(); pq.pop();
                   ans.push_back(ch2);
                   if(cnt2 > 1) pq.push({cnt2-1,ch2}); 
                   pq.push({cnt-1,ch});
               }
           }
           else {
               ans.push_back(ch);
           }
       }
       return ans;
    }
};