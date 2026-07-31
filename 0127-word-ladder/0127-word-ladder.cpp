class Solution {
public:
    int isNei(string t, string u) {
        int k = 1;
        for (int i = 0; i < u.size(); i++) {
            if (t[i] != u[i])
                k--;
            if (k < 0)
                return false;
        }
        if (k == 0)
            return true;
        return false;
    }
    int minPath(int start, int end, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        visited[start] = true;

        queue<int> bfs;
        bfs.push(start);
        while (!bfs.empty()) {
            int x = bfs.front();
            bfs.pop();

            if (x == end)
                break;
            for (int n : adj[x]) {
                if (!visited[n]) {
                    bfs.push(n);
                    visited[n] = true;
                    parent[n] = x;
                }
            }
        }
        if (!visited[end])
            return 0;
        vector<int> path;
        for (int v = end; v != -1; v = parent[v])
            path.push_back(v);

        return path.size();
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        vector<vector<int>> adjList(wordList.size() + 1);
        int fn = -1, ln = -1;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord)
                ln = i;
            if (wordList[i] == beginWord)
                fn = i;
        }
        if (fn == -1) {
            wordList.push_back(beginWord);
            fn = wordList.size() - 1;
        }
        for (int i = 0; i < wordList.size(); i++) {
            string t = wordList[i];

            for (int j = 0; j < wordList.size(); j++) {
                if (isNei(t, wordList[j])) {
                    adjList[i].push_back(j);
                }
            }
        }
        if (ln == -1)
            return 0;
        // fn -> ln min path
        return minPath(fn, ln, adjList);
    }
};