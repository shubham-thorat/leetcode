class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char,int> mp;
        for(const auto &e:s) mp[e] += 1;
        int n = s.length();
        if(n == 0) return "";
    unordered_set<char> inc;
        for(int i=0;i<s.length();i++){
            
            while(!st.empty() && mp[st.top()] >= 1 && st.top() > s[i] && inc.find(s[i]) == inc.end()){
                inc.erase(st.top());
                st.pop();
            }
            
            if(inc.find(s[i]) == inc.end()) {
                st.push(s[i]);
                inc.insert(s[i]);
            }
            mp[s[i]] -= 1;
        }
        
        
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};