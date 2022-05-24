// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// c
typedef long long ll;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll arr[],int lo,int mid,int hi) {
        int n1 = mid - lo + 1;
        int n2 = hi - mid;
        ll arr1[n1],arr2[n2];
        ll count = 0;
        for(int i=lo;i<=mid;i++) {
            arr1[i - lo] = arr[i];
        }
        
        for(int i=mid + 1;i<=hi;i++) {
            arr2[i - (mid + 1)] = arr[i];
        }
        int i = 0,j = 0,k = 0;
        while(j < n1 && k < n2) {
            if(arr1[j] <= arr2[k]) {
                arr[i + lo] = arr1[j];
                j++;
            }
            else {
                arr[i + lo] = arr2[k];
                count += (n1 - j);
                k++;
            }
            i++;
        }
        
        while(j < n1) {
            arr[i + lo] = arr1[j];
            j++;
            i++;
        }
        
        while(k < n2) {
            arr[i + lo] = arr2[k];
            k++;
            i++;
        }
        return count;
    }
    long long mergesort(ll arr[],int lo,int hi) {
        if(lo < hi) {
            ll mid = (lo + hi)/2;
            
            ll l = mergesort(arr,lo,mid);
            ll r = mergesort(arr,mid + 1,hi);
            
            ll result = merge(arr,lo,mid,hi);
            
            return l + r + result; 
        }
        return 0;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        // long long count = 0;
        // for(int i=0;i<N-1;i++) {
        //     for(int j=i+1;j<N;j++) {
        //         if(arr[i] > arr[j]) count+=1;
        //     }
        // }
        // return count;
        
        
        return mergesort(arr,0,(int)N-1);
        
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends