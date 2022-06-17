class Solution {
public:
    bool checkAvailable(vector<string> &grid,int row,int col) {
        int i = row,j = col;
        int n = grid.size();
        
        while(i >= 0) {
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;
        }

        i = row,j = col;
        while(i>=0 && j >=0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        i = row,j = col;
        while(i>=0 && j < n) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        return true;
    }
    void solveQueen(int row,vector<string> &grid,vector<vector<string>> &totalPossible) {

        if(row == grid.size()) {
            totalPossible.push_back(grid);
            return;
        }
        int colSize = grid.size();
        for(int i=0;i<colSize;i++) {

            if(checkAvailable(grid,row,i)) {
                grid[row][i] = 'Q';
                solveQueen(row + 1,grid,totalPossible);
                grid[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string row(n,'.');
        vector<string> grid(n,row);

        vector<vector<string>> totalPossible;

        solveQueen(0,grid,totalPossible);
        return totalPossible;
    }
};
