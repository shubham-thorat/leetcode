// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *nums, int n) {
       
       long long missrepeatsquarediff = 0;
       long long missrepeatdiff = 0;
       for(int i=0;i<n;i++) {
           missrepeatsquarediff += (1LL * nums[i] * nums[i]) - (1LL * (i+1)*(i+1));
           missrepeatdiff += (long long)(nums[i] - (i+1));
       }
       
       long long missrepeatsum = (missrepeatsquarediff/missrepeatdiff);
       
       
       int repeat = (missrepeatsum + missrepeatdiff)/2;
        int miss =  (missrepeatsum - missrepeatdiff)/2;
        
        return new int[2]{repeat,miss};
       
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