// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dept[], int n)
    {
    	// Your code here
    	sort(arr,arr + n);
    	sort(dept,dept + n);
    	if(n == 0) return 0;
    	int curr_plat = 1;
    	int i = 1,j = 0;
    	int ans = 1;
    	while(i < n){
    	    while(j <= i && dept[j] < arr[i]){
    	        curr_plat--;
    	        j++;
    	    }
    	    if(j <= i && arr[i] <= dept[j]){
    	        curr_plat++;
    	    }
    	    ans = max(ans,curr_plat);
    	    i++;
    	}
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends