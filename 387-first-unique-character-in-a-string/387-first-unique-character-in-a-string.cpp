class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> v(26,{0,0});
        
        for(int i=0;i<s.length();i++){
            char e = s[i];
            v[e - 'a'].first += 1;
            if(v[e - 'a'].first == 1){
                v[e - 'a'].second = i;
            }
        }
        
        for(auto &e:s){
            if(v[e - 'a'].first == 1){
                return v[e-'a'].second;
            }
        }
        return -1;
    }
};