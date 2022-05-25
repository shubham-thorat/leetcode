// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rem(string s) {
        int n = s.length();
        string ans = "";
        for(int i=0;i<s.length();i++) {
            if((i == 0 || s[i] != s[i-1]) && (i == n-1 || s[i] != s[i+1])) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
    string rremove(string s){
        
        string ans = "";
        
        while(ans.length() != s.length()) {
            ans = s;
            
            s = rem(s);
        }
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends