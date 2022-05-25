// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
        void solve(string s,int idx,vector<string> &ans) {
            if(idx == s.length() - 1){
                ans.push_back(s);
                return;
            }
            
            for(int i=idx;i<s.length();i++) {
                if(i > idx && s[i] == s[i-1]) continue;
                swap(s[idx],s[i]);
                solve(s,idx + 1,ans);
                swap(s[idx],s[i]);
            }
        }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    solve(S,0,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends