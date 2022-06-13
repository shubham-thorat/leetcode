// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *nums, int n) {
        // code here
        int arr[n];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++) {
            arr[nums[i] - 1] += 1; 
        }
        
        int miss,repeat;
        for(int i=0;i<n;i++) {
            if(arr[i] == 0) {
                miss = i + 1;
            }
            if(arr[i] == 2) {
                repeat = i + 1;
            }
        }
        
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