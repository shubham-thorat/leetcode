// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        
        int flag = false,ans = 0,i = 0;
        if(str[0] == '-') {
            flag = true;
            i = 1;
        }
        for(;i<str.length();i++) {
            if(str[i] >= '0' && str[i] <= '9') {
                ans = ans * 10 + (str[i] - '0');
            }
            else return -1;
            
        }
        return (flag == true ? -ans : ans);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends