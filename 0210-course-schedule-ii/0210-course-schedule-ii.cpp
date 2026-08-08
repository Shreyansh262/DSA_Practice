class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adjList, vector<int>& isVis,
             vector<int>& path, vector<int>& pathVis) {
        isVis[i] = 1;
        pathVis[i] = 1;
        for (auto x : adjList[i]) {
            if (!isVis[x]) {
                if (!dfs(x, adjList, isVis, path ,pathVis))
                    return false;
            } else if (pathVis[x]) {
                return false;
            }
        }
        path.push_back(i);
        pathVis[i] = 0;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(n);
        vector<int> path;
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u);
        }
        vector<int> isVis(n, 0);
        vector<int> pathVis(n, 0);
        for (int i = 0; i < n; i++) {
            if (isVis[i])
                continue;
            if (!dfs(i, adjList, isVis, path, pathVis))
                return {};
        }
        reverse(path.begin(), path.end());
        return path;
    }
};