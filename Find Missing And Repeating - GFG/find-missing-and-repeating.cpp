// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *nums, int n) {
       
       int xor_total = 0;
       
       for(int i=0;i<n;i++) {
           xor_total = (xor_total ^ (i+1) ^ nums[i]);
           
       }
       
       int set_bits = (xor_total & ~(xor_total - 1));
       
       
       int x = 0,y = 0;
       for(int i=0;i<n;i++) {
           
           if((set_bits & nums[i]) != 0) {
               x = x ^ nums[i];
           }
           else {
               y = y ^ nums[i];
           }
           
           if(((i+1) & set_bits) != 0) {
               x = x ^ (i+1);
           }
           else {
               y = y ^ (i+1);
           }
       }
       int cnt = 0;
       for(int i=0;i<n;i++) {
           if(x == nums[i]) cnt++;
       }
       
       if(cnt == 2) return new int[2]{x,y};
       else return new int[2]{y,x};
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends