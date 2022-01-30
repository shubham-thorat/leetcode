class Solution {
public:
    
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        
        for(const char &ch:s){
            mp[ch] += 1;
        }
        
        int count = 0,odd = 0;
        for(auto e:mp){
           count += (e.second/2);
           
            if(e.second % 2 != 0){
                odd++;
            }
        }
        
        return (count * 2 + (odd > 0 ? 1 : 0));
    }
};