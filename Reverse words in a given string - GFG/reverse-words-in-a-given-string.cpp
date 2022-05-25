// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int hi = s.length() - 1;
        string ans = "";
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i] == '.') {
                ans += s.substr(i+1,hi - i);
                if(i != 0)
                    ans.push_back('.');
                hi = i - 1;
            }
        }
        
        ans += s.substr(0,hi + 1);
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends