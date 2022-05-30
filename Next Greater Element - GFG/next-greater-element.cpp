// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


typedef long long ll;
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code heren
        
        vector<ll> nextLarger(n);
        nextLarger[n-1] = -1;
        
        stack<int> indices;
        indices.push(n-1);
        
        for(int ptr = n-2;ptr>=0;ptr--) {
            while(!indices.empty() && arr[indices.top()] <= arr[ptr]) {
                indices.pop();
            }        
            
            if(indices.empty()) {
                nextLarger[ptr] = -1;
            }
            else {
                nextLarger[ptr] = arr[indices.top()];
            }
            
            indices.push(ptr);
        }
        
        return nextLarger;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends