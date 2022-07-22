class Solution {
public:
    void helper(int n,int countOpen,int countClose,vector<string> &ans,string curr) {
        if(countClose == n) {
            ans.push_back(curr);
            return;
        }
        
        if(countOpen < n) {
            helper(n,countOpen + 1,countClose,ans,curr + "(");
        }
        
        if(countClose < countOpen) {
            helper(n,countOpen,countClose + 1,ans,curr + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        int countOpen = 0,countClose = 0;
        helper(n,countOpen,countClose,ans,"");
        return ans;
    }
};

/*
int countOpen,countClose;

*/

// '(' -> countOpen < n 
    
// ')' -> countOpen < countClose 