// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> seq;
       for(int i=0;i<n;i++){
           //we can extend the sequence
             int ind = lower_bound(seq.begin(),seq.end(),a[i]) - seq.begin();
            if(ind == seq.size()){
                seq.push_back(a[i]);
            }
            else {
                seq[ind] = a[i];
            }
       }
       
       return seq.size();
    }
    
    
    
    // 5       8       3       7       9       1
    
    // 1       2       1       2       3       1
    // 1       2       1       2       3       1
    
    
    
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends