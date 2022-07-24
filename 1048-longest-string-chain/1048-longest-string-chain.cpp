class Solution {
public:
    static bool mysort(string &a,string &b) {
        return a.length() > b.length();
    }
    int helper(string word,unordered_set<string> &dict) {
        int ans = 0;
        dict.erase(word);
        for(int i=0;i<=word.length();i++) {
            string str = word.substr(0,i) +  word.substr(min((int)word.length(),i + 1));
            if(dict.find(str) != dict.end()) {
                int temp = helper(str,dict) + 1;
                ans = max(ans,temp);
            }
        }
        return ans;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),mysort);
        unordered_set<string> dict;
        
        for(auto &e:words) {
            dict.insert(e);
        }
        
        int ans = 0;
        for(int i=0;i<words.size();i++) {
            if(dict.find(words[i]) != dict.end())
                ans = max(ans,helper(words[i],dict) + 1);
        }
        return ans;
    }
};
