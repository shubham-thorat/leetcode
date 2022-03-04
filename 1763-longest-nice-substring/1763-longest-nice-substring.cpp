class Solution {
public:
    string longestNiceSubstring(string s) {
        int ans = 0;
        string str = "";
        for(int i=0;i<s.length();i++){
            unordered_set<char> st;
            for(int j=i;j<s.length();j++){
                st.insert(s[j]);
                bool istrue = true;
                for(const char &ch:st){
                    if(ch >= 'A' && ch <= 'Z' && st.find(tolower(ch)) == st.end()){
                        istrue = false;
                        break;
                    }
                    else if(ch >= 'a' && ch <= 'z' && st.find(toupper(ch)) == st.end()){
                        istrue = false;
                        break;
                    }
                }
                if(istrue && (j-i + 1) > ans){
                    ans = j - i + 1;
                    str = s.substr(i,ans);
                }
            }
        }
        return str;
    }
};