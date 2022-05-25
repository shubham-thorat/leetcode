// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  int palidrome(int lo,int hi,string s) {
        while(lo >=0 && hi < s.length() && lo <= hi) {
            if(s[lo] == s[hi]) {
                lo--;
                hi++;
            }
            else break;
        }     
        
        return (hi - lo - 1);
  }
    string longestPalin (string s) {
        // code here
        
        int n = s.length();
        if(n == 0) return 0;
        int ans = 1,start_idx = 0;
        for(int i=0;i<n-1;i++) {
            int len1 = palidrome(i,i,s);
            int len2 = palidrome(i,i + 1,s);
                        
            if(len1 > len2) {
                if(ans < len1) {
                    ans = len1;
                    start_idx = i - ((ans- 1)/2);
                }
            }
            else {
                if(ans < len2) {
                    ans = len2;
                    start_idx = i - ((ans- 1)/2);
                }        
            }
        }
    return s.substr(start_idx,ans);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends