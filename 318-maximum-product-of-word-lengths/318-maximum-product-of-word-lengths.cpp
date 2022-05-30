class Solution {
public:
    int maxProduct(vector<string>& words) {
        int wordsLen = words.size();
        
        vector<int> masks(wordsLen,0);
        
        for(int i=0;i<wordsLen;i++) {
            for(int j=0;j<words[i].length();j++) {
                masks[i] = (masks[i] | (1<<(words[i][j] - 'a')));
            }
        }
        
        // for(int i=0;i<wordsLen;i++) {
        //     cout << masks[i] << " ";
        // }
        // cout << endl;
        
        int ans = 0;
        for(int i=0;i<wordsLen;i++) {
            for(int j=i+1;j<wordsLen;j++) {
                if(!(masks[i] & masks[j])) {
                    // cout << i << " " << j <<endl;
                    int t = words[i].length() * words[j].length();
                    ans = max(ans,t);
                }
            }
        }
        return ans;
    }
};