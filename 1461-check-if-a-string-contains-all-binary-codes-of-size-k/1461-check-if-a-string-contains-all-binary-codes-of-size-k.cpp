class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (1<<k);         
        if(k > s.length()) return 0;
        
        unordered_set<string> st;
        
        for(int i=0;i<=s.length()-k;i++) {
            st.insert(s.substr(i,k));
        }
        
        return (st.size() == n);
    }
};