class Solution {
public:
    vector<int> decode(vector<int>& en, int first) {
        vector<int> ans;
        ans.push_back(first);
        
        for(int i=0;i<en.size();i++){
            ans.push_back(ans.back() ^ en[i]);
        }
        return ans;
    }
};