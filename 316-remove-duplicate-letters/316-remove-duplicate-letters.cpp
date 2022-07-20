class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<bool> vis(26,false);
        stack<char> st;
        unordered_map<char,int> count;
        
        for(auto &e:s) count[e] += 1;
        
        
        for(int i=0;i<s.length();i++) {
            
            while(!st.empty() && st.top() > s[i] && count[st.top()] >= 1 && vis[s[i] - 'a'] == false) {
                 vis[st.top() - 'a'] = false;
                st.pop();
            }
            
            if(vis[s[i] - 'a'] == false) {
                st.push(s[i]);
                vis[s[i] - 'a'] = true;
            }
            
            count[s[i]]--;
        }
        
        string ans = "";
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// "abacb"
    
    
    // acb