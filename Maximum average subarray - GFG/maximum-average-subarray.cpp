// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
      
      int pref[n] = {0};
      pref[0] = arr[0];
      for(int i=1;i<n;i++){
          pref[i] = pref[i-1]+arr[i];
      }
     
      int curr_val = pref[k-1];
      int i=1,j=k,max_so_far=curr_val,idx=0;
      
      while(j<n){
          int curr_val = (pref[j]-pref[i-1]);
          if(curr_val>max_so_far){
              max_so_far = curr_val;
              idx = i;
          }
          i++;
          j++;
      }
      
      return idx;
      
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends