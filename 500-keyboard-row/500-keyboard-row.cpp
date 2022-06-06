class Solution {
public:
    vector<string> findWords(vector<string>& words) {
       vector<string> keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        
        vector<int> map(26);
        for (int row = 0; row < 3; row++) {
            for (auto ch : keyboard[row]) {
                map[ch - 'a'] = row;
            }
        }
        
        vector<string> res;
        bool flag = true;
        
        for (auto word : words) {
            flag = true;
            int idx = map[tolower(word[0]) - 'a'];
            
            for (auto ch : word) {
                if (map[tolower(ch) - 'a'] != idx) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        
        return res;
        
    }
};