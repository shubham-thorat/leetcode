// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
// c
typedef long long ll;
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        ll sum = 0;
        for(int i=0;i<n;i++) sum += a[i];
        ll curr_sum = 0;
        for(int i=0;i<n;i++) {
            int right_sum = sum - curr_sum - a[i];
            
            if(curr_sum == right_sum) {
                return i + 1;
            }
            curr_sum += a[i];
        }
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends