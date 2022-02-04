class Solution {
    boolean ok(String word,int r,int c,int index,char board[][]){
        if(index == word.length()){
            return true;
        }
        char ch = board[r][c];
        board[r][c] = '#';
        int X[] = new int[]{0,0,1,-1};
        int Y[] = new int[]{1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx = X[i] + r;
            int ny = Y[i] + c;
            if(nx>=0 && ny>=0 && nx<board.length && ny < board[0].length && board[nx][ny] == word.charAt(index)){
                if(ok(word,nx,ny,index + 1,board)){
                    return true;
                }
            }
        }
        board[r][c] = ch;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word.charAt(0)){
                    if(ok(word,i,j,1,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}