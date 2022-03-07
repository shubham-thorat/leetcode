// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({start[i],end[i]});
        
        sort(v.begin(),v.end(),[](pair<int,int> &p1,pair<int,int> &p2){
           if(p1.second != p2.second) return p1.second < p2.second;
           else return p1.first < p2.first;
        });
        if(n == 0) return 0;
        int count = 0;
        int y = v[0].second;
        for(int i=1;i<n;i++){
            if(y < v[i].first){
                y = v[i].second;
                count++;
            }
        }
        return count + 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends