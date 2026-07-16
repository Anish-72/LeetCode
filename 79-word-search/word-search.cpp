class Solution {
public:
    bool isexist(vector<vector<char>>& board, string word, int n, int m, int i, int r, int c) {
        if (r < 0 || c < 0 || r > n - 1 || c > m - 1) {
            return false;
        }

        if (board[r][c] != word[i]) {
            return false;
        }

        if (i == word.length() - 1) {
            return true;
        }

        char original_char = board[r][c];
        board[r][c] = '*';

        if (isexist(board, word, n, m, i + 1, r + 1, c)) return true; 
        if (isexist(board, word, n, m, i + 1, r - 1, c)) return true; 
        if (isexist(board, word, n, m, i + 1, r, c + 1)) return true; 
        if (isexist(board, word, n, m, i + 1, r, c - 1)) return true; 

        board[r][c] = original_char;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                if (isexist(board, word, n, m, 0, k, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};