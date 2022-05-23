// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
      
      unordered_map<char,int> m;
      for(int i=0;i<S1.length();i++){
          m[S1[i]] = i;
      }
      int curr = 0, ans = 0;
      for(int i=0;i<S2.length();i++){
          ans+=abs(curr-m[S2[i]]);
          curr = m[S2[i]];
      }
      
      return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends