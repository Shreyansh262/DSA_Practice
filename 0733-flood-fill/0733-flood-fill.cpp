class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int ogc = image[sr][sc];
        image[sr][sc] = color;
        if(ogc==color) return image;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        while (!q.empty()) {
            int sz = q.size();
            for (int z = 0; z < sz; z++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int cr = r + dr[i];
                    int cc = c + dc[i];
                    if (cr >= 0 && cc >= 0 && cr < image.size() &&
                        cc < image[0].size() && image[cr][cc] == ogc) {
                        image[cr][cc] = color;
                        q.push({cr, cc});
                    }
                }
            }
        }
        return image;
    }
};