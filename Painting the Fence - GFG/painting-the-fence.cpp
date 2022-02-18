// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends


typedef long long ll;
class Solution{
    public:
    ll mod = (1e9 + 7);
    long long countWays(int n, int k){
        // code here
        if(n == 0) return 0;
        if(n == 1) return (ll)(k);
        long long prev_same = (k%mod),prev_diff = (k * (k-1))%mod;
        for(int i=3;i<=n;i++){
            ll curr_same = (prev_diff * 1LL)%mod;
            ll curr_diff = ((prev_same + prev_diff) * (k-1))%mod;
            
            prev_same = curr_same;
            prev_diff = curr_diff;
        }
        return (prev_same + prev_diff)%mod;
    }
};




// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends