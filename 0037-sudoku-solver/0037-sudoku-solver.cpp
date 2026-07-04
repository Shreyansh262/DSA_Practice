class Solution {
public:
    bool isValid(int r, int c, char n, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == n)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == n)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == n)
                return false;
        }
        return true;
    }
    bool solver(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isValid(i, j, k, board)) {
                            board[i][j] = k;
                            if (solver(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {solver(board); }
};