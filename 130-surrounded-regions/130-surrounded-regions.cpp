class Solution {
public:
    void dfs(vector<vector<char>> &board,int r,int c){
        board[r][c] = '#';
        int X[] = {0,0,1,-1};
        int Y[] = {1,-1,0,0};
        // cout<<r<<" "<<c<<endl;
        for(int i=0;i<4;i++){
            int nx = X[i] + r;
            int ny = Y[i] + c;
            if(nx >=0 && ny >=0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 'O'){
                dfs(board,nx,ny);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        
        int m = board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                dfs(board,0,i);
            }
                
            
            if(board[n-1][i] == 'O'){
                dfs(board,n-1,i);
            }
                
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O')
                dfs(board,i,0);
            
            
            if(board[i][m-1] == 'O')
                dfs(board,i,m-1);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                    
                
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};