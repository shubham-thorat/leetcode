class Solution {
public:
   string reorganizeString(string s) {
        
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        
        if(m.size()==1) return "";
        priority_queue<pair<int,char>> maxh;
        for(auto i : m){
            maxh.push({i.second,i.first});
        }
        string ans = "";
        pair<int,char> block = maxh.top();
       maxh.pop();
        ans+=block.second;
        block.first--;
        
        while(maxh.size()>0){
            pair<int,char> temp = maxh.top(); maxh.pop();
            ans+=temp.second;
            temp.first--;
            if(block.first>0) maxh.push(block);
            block = temp;
        }
        
        if(block.first>0) return "";
        return ans;
        
    }
};