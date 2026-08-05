class DSU {
private:
    vector<vector<int>> bts;
    vector<int> p;
    vector<int> rank;

public:
    DSU(int n) {
        bts.resize(n);
        p.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int parent(int i) {
        if (p[i] == i)
            return i;
        return p[i] = parent(p[i]);
    }
    void join(int i, int j) {
        if (parent(i) == parent(j))
            return;
        else {
            if (rank[i] > rank[j])
                p[j] = i;
            else if (rank[i] < rank[j])
                p[i] = j;
            else {
                p[j] = i;
                rank[i]++;
            }
        }
    }
};
class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < invocations.size(); i++) {
            int x = invocations[i][0];
            int y = invocations[i][1];
            adjList[x].push_back(y);
        }
        vector<bool> sus(n, false);
        queue<int> curr;
        curr.push(k);
        sus[k] = true;
        while (!curr.empty()) {
            int t = curr.front();
            curr.pop();
            for (int i : adjList[t]) {
                if (!sus[i]) {
                    sus[i] = true;
                    curr.push(i);
                }
            }
        }
        bool canRem = true;
        for (int i = 0; i < invocations.size(); i++) {
            int x = invocations[i][0];
            int y = invocations[i][1];

            if (!sus[x] && sus[y]) {
                canRem = false;
                break;
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!canRem || !sus[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
