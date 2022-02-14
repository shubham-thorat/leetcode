// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	private:
	long int costOfOperation(int n, int h[], int cost[], 
							int eq_h) 
	{ 
		long int c = 0; 

		for (int i = 0; i < n; i++) 
			c += abs(h[i] - eq_h) * cost[i]; 

		return c; 
	} 

	public:
	long long int Bsearch(int n, int h[], int cost[]) 
	{ 
		long int max_h = *max_element(h, h + n); 
		long int ans = LONG_MAX; 

		long int high = 1 + max_h; 
		long int low = 0; 
		while (high > low) { 
			int mid = (low + high) >> 1; 

			long int bm = (mid > 0) ? 
					costOfOperation(n, h, cost, mid - 1) : 
					LONG_MAX; 

			long int m = costOfOperation(n, h, cost, mid); 

			long int am = costOfOperation(n, h, cost, mid + 1); 


			ans = min(ans, m); 

			if (bm <= m) 
				high = mid; 

			else if (am <= m) 
				low = mid + 1; 

			else
				return m;
		}

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
    	 int n;
        cin>>n;
        
        int h[n], c[n];
        for(int i=0; i<n; i++)
            cin>>h[i];
        
        for(int i=0; i<n; i++)
            cin>>c[i];
            
        
        

        Solution ob;
		cout << ob.Bsearch(n,h,c);
        
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends