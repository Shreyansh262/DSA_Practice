class Solution {
public:
    bool finder(int i, int x, int y, vector<vector<char>>& board, string& word,
                vector<int>& drow, vector<int>& dcol, int m, int n,
                vector<vector<int>>& isVisited) {
        if (i == word.size())
            return true;

        for (int j = 0; j < 4; j++) {
            if (x + drow[j] >= 0 && x + drow[j] < m && y + dcol[j] >= 0 &&
                y + dcol[j] < n && isVisited[x + drow[j]][y + dcol[j]] == 0 &&
                board[x + drow[j]][y + dcol[j]] == word[i]) {
                isVisited[x + drow[j]][y + dcol[j]] = 1;
                if (finder(i + 1, x + drow[j], y + dcol[j], board, word, drow,
                           dcol, m, n, isVisited))
                    return true;
                isVisited[x + drow[j]][y + dcol[j]] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> drow = {1, 0, -1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        bool res = false;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == word[0]) {
                    isVisited[x][y] = 1;
                    res = finder(1, x, y, board, word, drow, dcol, m, n,
                                 isVisited);
                    if(res) return true;
                    isVisited[x][y] = 0;
                }
            }
        }
        return false;
    }
};