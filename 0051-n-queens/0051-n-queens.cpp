class Solution {
public:
    bool isValid(int r, int c, int n, vector<int>& rmap, vector<int>& d1map,
                 vector<int>& d2map) {
        if (rmap[r] == 0 && d1map[r + c] == 0 && d2map[n - 1 + c - r] == 0)
            return true;
        return false;
    }
    void nQueens(vector<string>& board, int n, int col, vector<int>& rmap,vector<int>& d1map, vector<int>& d2map,vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int r = 0; r < n; r++) {
            if (isValid(r, col, n, rmap, d1map, d2map)) {
                board[r][col] = 'Q';
                rmap[r] = 1;
                d1map[r + col] = 1;
                d2map[n - 1 + col-r] = 1;
                nQueens(board, n, col + 1, rmap, d1map, d2map,ans);
                board[r][col] = '.';
                rmap[r] = 0;
                d1map[r + col] = 0;
                d2map[n - 1 +col-r] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        vector<int> rmap(n, 0);
        vector<int> d1map(2 * n - 1, 0);
        vector<int> d2map(2 * n - 1, 0);
        nQueens(board, n, 0, rmap, d1map, d2map, ans);
        return ans;
    }
};