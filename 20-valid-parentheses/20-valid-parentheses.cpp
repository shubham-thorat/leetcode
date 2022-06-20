class Solution {
    
    bool pairs(char opening,char closing){
        
        if((opening=='(' && closing==')') || (opening=='{' && closing=='}') || (opening=='[' &&closing==']')) return true;
        return false;
    }
public:
    bool isValid(string s) {
        
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.size()==0 || pairs(st.top(),s[i])==false) return false;
                else st.pop();
            }
        }
        
        return (st.size()==0) ? true : false;
        
    }
    
};