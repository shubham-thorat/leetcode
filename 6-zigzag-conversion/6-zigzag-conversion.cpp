class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        
        vector<vector<char>> v(n);
        
        bool inc  = true;
        int i = 0;
        for(int j=0;j<s.length();j++){
            v[i].push_back(s[j]);
            if(inc == true){
                i += 1;    
            }
            else {
                i -= 1;
            }
            
            if(i == n){
                i = n - 2;
                inc = false;
            }
            else if(i == -1){
                i = 1;
                inc = true;
            }
        }
        string str = "";
        for(int i=0;i<n;i++){
            for(auto e:v[i]){
                str.push_back(e);
            }
        }
        return str;
    }
};