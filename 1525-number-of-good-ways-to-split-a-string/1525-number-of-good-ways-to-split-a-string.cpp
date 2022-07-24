class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> first,second;
        
        for(char &ch:s) {
            second[ch] += 1;
        }
        second[s[0]]--;
        first[s[0]]++;
        if(second[s[0]] == 0) {
            second.erase(s[0]);
        } 
        
        int count = 0;
        for(int i=1;i<s.length();i++) {
            if(first.size() == second.size()) {
                count++;
            }
            
            first[s[i]]++;
            second[s[i]]--;
            
            if(second[s[i]] == 0) {
                second.erase(s[i]);
            }
        }
        return count;
    }
};