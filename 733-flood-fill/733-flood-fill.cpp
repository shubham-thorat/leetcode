class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0) return image;
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor=image[sr][sc];
        vector<vector<bool>> seen(m,vector<bool>(n,false));
        seen[sr][sc] = true;
      
        image[sr][sc] = newColor;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            seen[i][j] = true;
            if(i<m-1 && image[i+1][j]==oldColor && !seen[i+1][j]){
                q.push({i+1,j});
                image[i+1][j] = newColor;
            }
            if(i>0 && image[i-1][j]==oldColor  && !seen[i-1][j]){
                q.push({i-1,j});
                image[i-1][j] = newColor;
            }
            if(j<n-1 && image[i][j+1]==oldColor  && !seen[i][j+1]){
                q.push({i,j+1});
                image[i][j+1] = newColor;
            }
            if(j>0 && image[i][j-1]==oldColor  && !seen[i][j-1]){
                q.push({i,j-1});
                image[i][j-1] = newColor;
            }
        }
        return image;
    }
};