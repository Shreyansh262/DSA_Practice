class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) { return rot(grid); }
    int rot(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int cnt = 0;
        int chcng = 0;
        int time = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    cnt++;
            }
        }
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        while (!q.empty()) {
            int sz = q.size();
            bool change = false;
            for (int j = 0; j < sz; j++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int crr = r + drow[i];
                    int crc = c + dcol[i];
                    if (crr < m && crr >= 0 && crc >= 0 && crc < n &&
                        grid[crr][crc] == 1) {
                        chcng++;
                        q.push({crr, crc});
                        grid[crr][crc] = 2;
                        change = true;
                    }
                }
            }
            if(change) time++;
        }
        if (cnt != chcng)
            return -1;
        else
            return time;
    }
};