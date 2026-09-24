class Solution {
private:
    void solve(vector<vector<string>>& ans, vector<string>& board, int col, int n,
               vector<int>& leftRow, vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && upperDiagonal[(n - 1 + col - row)] == 0 &&
                lowerDiagonal[row + col] == 0) {

                leftRow[row] = 1;
                upperDiagonal[(n - 1 + col - row)] = 1;
                lowerDiagonal[row + col] = 1;
                board[row][col] = 'Q';
               

                solve(ans, board, col + 1, n, leftRow, upperDiagonal,
                      lowerDiagonal);

                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
                lowerDiagonal[row + col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string str(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = str;
        }
        vector<int> leftRow(n, 0), upperDiagnol(2 * n - 1, 0),
            lowerDiagonal(2 * n - 1, 0);
        solve(ans, board, 0, n, leftRow, upperDiagnol, lowerDiagonal);
        return ans;
    }
};