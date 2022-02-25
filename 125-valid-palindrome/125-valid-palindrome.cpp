class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0;i<s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                str.push_back(s[i]);
            }
            else if(s[i] >='0' && s[i] <= '9'){
                str.push_back(s[i]);
            }
        }
        // cout<<str<<endl;
        int i = 0,j=str.length() - 1;
        while(i < j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};