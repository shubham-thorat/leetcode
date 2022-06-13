// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *nums, int n) {
        // code here
        
        int *ans = new int[2];
        
        sort(nums,nums + n);
        int current = 1,miss = 0,repeat = -1;
        
          for (int i = 1; i < n; i++) 
        {
            if (nums[i] == nums[i - 1]) 
            {
                // Found the repeating number.
                repeat = nums[i];
                break;
            }
        }

        int nextNum = 1;
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == nextNum) 
            {
                ++nextNum;
                if (nums[i] == repeat) 
                {
                    ++i;
                }
            }
            else 
            {
                // Found the missing number.
                break;
            }
        }

        miss = nextNum;

        return new int[2]{repeat, miss};
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