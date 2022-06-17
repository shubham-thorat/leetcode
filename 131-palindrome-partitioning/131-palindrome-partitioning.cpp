class Solution {
public:
    bool isPalidrome(string s) {
        int low = 0,high = s.length() - 1;
        
        while(low < high) {
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    void palidromePartition(string s,int index,vector<string> &currentPartition,vector<vector<string>>  &possiblePartitions) {
        
        if(index == s.length()) {
            possiblePartitions.push_back(currentPartition);
            return;
        }
        
        string str = "";
        for(int i=index;i<s.length();i++) {
            str.push_back(s[i]);
            
            if(isPalidrome(str)) {
                currentPartition.push_back(str);
                palidromePartition(s,i+1,currentPartition,possiblePartitions);
                currentPartition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> possiblePartitions;
        vector<string> currentPartition;
        
        palidromePartition(s,0,currentPartition,possiblePartitions);
        return possiblePartitions;
    }
};