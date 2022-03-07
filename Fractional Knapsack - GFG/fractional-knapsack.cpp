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
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       sort(arr,arr+n,[](Item i1,Item i2){
            return ((1.0 * i1.value/i1.weight) > (1.0 * i2.value/i2.weight)); 
       });
        
        double sum = 0;
        for(int i=0;i<n;i++){
            if(W >= arr[i].weight){
                W = W - arr[i].weight;
                sum += arr[i].value;
            }
            else {
                sum +=  W * (1.0 * arr[i].value/arr[i].weight);
                break;
            }
        }
        return sum;
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