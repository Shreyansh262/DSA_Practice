class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        // 0 unvisited
        // 1 set red
        // 2 set blue
        for (int i = 0; i < n; i++) {

            if (color[i] != 0) {
                continue;
            }
            if (color[i] == 0) {
                color[i] = 1;
            }
            queue<int> bfs;
            bfs.push(i);
            while (!bfs.empty()) {
                int k = bfs.front();
                bfs.pop();
                for (int j : graph[k]) {
                    if (color[j] == 0) {
                        color[j] = color[k] ^ 3;
                        bfs.push(j);
                    } else if (color[j] == color[k]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};