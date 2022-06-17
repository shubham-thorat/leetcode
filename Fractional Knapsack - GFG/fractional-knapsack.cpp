// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool mysort(const Item &a,const Item &b) {
        
        return ((a.value * b.weight) > (b.value * a.weight));
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       double ans = 0.0;
       
       sort(arr,arr + n,mysort);
       
       for(int i=0;i<n;i++) {
           if(W >= arr[i].weight) {
               W = W - arr[i].weight;
               ans += arr[i].value;
           }
           else {
               ans += (1.0 * W/arr[i].weight) * arr[i].value;
                break;
           }
       }
       return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends