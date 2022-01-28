// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:

    int helper(int N){
        if(N == 0) return 1;
        if(N == 2) return 1;
        
        int ans = 0;
        for(int i=0;i<N;i+=2){
            int temp = helper(i) * helper(N-i-2);
            ans += temp;
        }
        return ans;
    }
    int count(int N){
        // code here
        if(N%2 != 0) return 0;
        
        return helper(N);
    }
};

// c6 = c0 * c4 + c2 * c2 + c4 * c0
// c0 = 1

// c2 = 1
// c3 = 0
// c4 = c0*c2 + c0*c2 = 2

// c6 = c4 * c0 + c2 * c4 + c0 * c6


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends