class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> v(26,0);
        for(auto &e:s) v[e - 'a'] += 1;
        
        int prev = v[s[0] - 'a'];
        for(int i=0;i<26;i++){
            if(v[i] != 0 && v[i] != prev) return false;
        }
        return true;
    }
};