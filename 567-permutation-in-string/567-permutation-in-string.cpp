class Solution {
public:
    bool check(unordered_map<char,int> count,unordered_map<char,int> chars){
        
        for(auto e:chars){
            if(count[e.first] != e.second) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        if(n > m)return false;
        
        unordered_map<char,int> count,chars;
        for(int i=0;i<n;i++){
            chars[s1[i]] += 1;
            count[s2[i]] += 1;
        }
        
        if(check(count,chars)) return true;
            
        for(int i=n;i<m;i++){
            count[s2[i-n]] -= 1;
            count[s2[i]] += 1;
            if(check(count,chars)){
                return true;
            }
        }
        return false;
    }
};