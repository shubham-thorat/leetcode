class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        for(auto &e:arr){
            if(e % 2 == 0 && mp.find(e/2) != mp.end()){
                return true;
            }
            
            if(mp.find(e*2) != mp.end()){
                return true;
            }
            mp[e] += 1;
        }
        return false;
    }
};