// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string pat) {
	    // Your code goes here
	    int n = pat.length();
	    int lps[n];
	    int i = 0;
        lps[0] = 0; // lps[0] is always 0
      
        // the loop calculates lps[i] for i = 1 to M-1
        int j = 1;
        while (j < n) {
            if (pat[j] == pat[i]) {
                i++;
                lps[j] = i;
                j++;
            }
            else // (pat[i] != pat[i])
            {
                // This is tricky. Consider the example.
                // AAACAAAA and i = 7. The idea is similar
                // to search step.
                if (i != 0) {
                    i = lps[i - 1];
                    // Also, note that we do not increment
                    // i here
                }
                else // if (i == 0)
                {
                    lps[j] = 0;
                    j++;
                }
            }
        }
        return lps[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends