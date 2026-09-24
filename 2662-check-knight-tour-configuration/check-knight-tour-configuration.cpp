class Solution {
private:
   bool solve(vector<vector<int>>& grid, int row, int col, int count, int n) {
        if(row < 0 || col < 0 ||  row > n -1 || col > n-1){
            return false;
        }
        if (grid[row][col] != count) {
            return false;
        }
        if (count == (n * n - 1)) {
            return true;
        }
        
        if (solve(grid, row + 2, col + 1, count + 1, n) ||
            solve(grid, row + 2, col - 1, count + 1, n) ||
            solve(grid, row - 2, col + 1, count + 1, n) ||
            solve(grid, row - 2, col - 1, count + 1, n) ||
            solve(grid, row + 1, col + 2, count + 1, n) ||
            solve(grid, row - 1, col + 2, count + 1, n) ||
            solve(grid, row + 1, col - 2, count + 1, n) ||
            solve(grid, row - 1, col - 2, count + 1, n)) 
        {
            return true;
        }
        return false;
    }

public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

       return solve(grid,0,0,0,n);

    }
};