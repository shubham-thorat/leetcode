class Solution {
    private void dfs(char board[][],int r,int c){
        board[r][c] = '#';
        int n = board.length;
        int m = board[0].length;
        int X[] = new int[]{0,0,1,-1};
        int Y[] = new int[]{1,-1,0,0};
        for(int i=0;i<4;i++){
            int next_r = X[i] + r;
            int next_c = Y[i] + c;
            if(next_r >=0 && next_c >=0 && next_r < n && next_c < m && board[next_r][next_c] == 'O'){
                dfs(board,next_r,next_c);
            }
        }
    }
    public void solve(char[][] board) {
        int n = board.length;
        if(n == 0) return;
        int m = board[0].length;
        
        for(int i=0;i<n;i++){
            //traversing left column
            if(board[i][0] == 'O')
                dfs(board,i,0);
            
            //traversing right column
            if(board[i][m-1] == 'O')
                dfs(board,i,m-1);
        }
        
        for(int i=0;i<m;i++){
            //traversing top row
            if(board[0][i] == 'O')
                dfs(board,0,i);
            
            //traversing bottom row
            if(board[n-1][i] == 'O')
                dfs(board,n-1,i);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
}