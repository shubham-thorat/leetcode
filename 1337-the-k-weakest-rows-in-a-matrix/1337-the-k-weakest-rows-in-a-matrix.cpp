typedef pair<int,int> p32;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<p32,vector<p32>,greater<p32>> pq;
        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]) count++;
            }
            pq.push({count,i});
            
            // if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};