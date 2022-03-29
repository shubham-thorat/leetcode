class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
       for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
           indegree[x[0]]++;
        }
        int cnt=0;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {        
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int top = q.front();
           // cout << top << " ";
            cnt++;
            q.pop();
            
            for(auto x:adj[top])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    //cout << 'r';
                    q.push(x);
                }
            }
        }
        //cout<<cnt<<endl;
        return cnt==n;
     
    }
};