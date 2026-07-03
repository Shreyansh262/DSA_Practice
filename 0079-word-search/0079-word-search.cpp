class Solution {
public:
    bool finder(int i, int x, int y, vector<vector<char>>& board, string& word) {
        if (i == word.size())
            return true;
        int m = board.size();
        int n = board[0].size();
        
        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};

       for (int j = 0; j < 4; j++) {
            int nextX = x + drow[j];
            int nextY = y + dcol[j];
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && 
                board[nextX][nextY] == word[i]) {
                char temp = board[nextX][nextY];
                board[nextX][nextY] = '0'; 
                if (finder(i + 1, nextX, nextY, board, word)) {
                    return true;
                }
                board[nextX][nextY] = temp; 
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool res = false;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == word[0]) {
                    char temp = board[x][y];
                    board[x][y] = '0';
                    res = finder(1, x, y, board, word);
                    if(res) return true;
                    board[x][y] = temp;
                }
            }
        }
        return false;
    }
};