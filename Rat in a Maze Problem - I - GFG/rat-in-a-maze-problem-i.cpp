// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int r,int c,vector<vector<int>> &m,int n,string curr,vector<string> &ans) {
        
        if(r == n-1 && c == n-1) {
            ans.push_back(curr);
            return;
        }
        
        m[r][c] = 0;
               //'R' 'L' 'D' 'U'
        string dir[]= {"R","L","D","U"};
        int X[] = {0,0,1,-1};
        int Y[] = {1,-1,0,0};
        for(int i=0;i<4;i++) {
            int nx = r + X[i];
            int ny = c + Y[i];
            if(nx>=0 && ny >=0 && nx < n && ny < n && m[nx][ny] == 1) {
                
                solve(nx,ny,m,n,curr + dir[i],ans);
            }
        }
        m[r][c] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(n == 0 || m[0][0]==0 || m[n-1][n-1] == 0) return {};
        
        vector<string> ans;
        string curr = "";
        solve(0,0,m,n,curr,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends