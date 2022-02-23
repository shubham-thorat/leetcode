class Solution {
    int bfs(int r,int c,int mat[][]){
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{r,c});
        int m = mat.length;
        int n = mat[0].length;
        boolean vis[][] = new boolean[m][n];
        int level = 0;
        vis[r][c] = true;
        int X[] = new int[]{0,0,1,-1};
        int Y[] = new int[]{1,-1,0,0};
        while(!q.isEmpty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int nums[] = q.poll();
                
                if(mat[nums[0]][nums[1]] == 0) return level;
                
                for(int j=0;j<4;j++){
                    int nx = nums[0] + X[j];
                    int ny = nums[1] + Y[j];
                    if(nx>=0 && ny>=0 && nx < m && ny < n && vis[nx][ny] == false){
                        q.add(new int[]{nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            level++;
        }
        return level;
    }
    int INF = 100000;
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        if(m == 0) return mat;
        int n = mat[0].length;
        int dist[][] = new int[m][n];
         Queue<int[]> q = new LinkedList<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.add(new int[]{i,j});
                    dist[i][j] = 0;
                }
                else dist[i][j] = INF;
            }
        }
        int X[] = new int[]{0,0,1,-1};
        int Y[] = new int[]{1,-1,0,0};
        while(!q.isEmpty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int nums[] = q.poll();
                
                for(int j=0;j<4;j++){
                    int nx = nums[0] + X[j];
                    int ny = nums[1] + Y[j];
                    if(nx>=0 && ny>=0 && nx < m && ny < n ){
                        
                        if(dist[nx][ny] > dist[nums[0]][nums[1]] + 1){
                            q.add(new int[]{nx,ny});    
                            dist[nx][ny] = dist[nums[0]][nums[1]] + 1;
                        }                        
                    }
                }
            }
        }
        return dist;
    }
}