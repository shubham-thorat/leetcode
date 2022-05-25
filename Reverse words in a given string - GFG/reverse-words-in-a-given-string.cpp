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
        vector<string> v;
        int lo = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '.') {
                v.push_back(s.substr(lo,i-lo));
                lo = i + 1;
            }
        }
        
        v.push_back(s.substr(lo));
        
        string str = "";
        
        for(int i=v.size() -1;i>=0;i--) {
            str += v[i];
            if(i != 0)
                str.push_back('.');
        }
        return str;
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