// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    unordered_set<char> st;
    int lo = 0,ans = 0;
    for(int i=0;i<s.length();i++) {
        
        while(lo <= i && st.find(s[i]) != st.end()) {
            st.erase(s[lo]);
            lo++;
        }
        st.insert(s[i]);
        ans = max(ans,i - lo + 1);
    }
    return ans;
}