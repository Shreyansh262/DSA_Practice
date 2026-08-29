class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // Apply DSU and join components possible to swap
        // Make answer array and at each position place to smallest member of
        // family present at that index return answer
        vector<pair<int, int>> a;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());
        DSU dsu(n);

        for (int i = 1; i < n; i++) {
            if (a[i].first - a[i - 1].first <= limit) {
                dsu.unite(a[i].second, a[i - 1].second);
            }
        }
        unordered_map<int, vector<int>> values;

        for (auto& [value, index] : a) {
            values[dsu.find(index)].push_back(value);
        }
        unordered_map<int, vector<int>> indices;

        for (int i = 0; i < n; i++) {
            indices[dsu.find(i)].push_back(i);
        }

        vector<int> ans(n);
        for (auto& [root, idx] : indices) {

            vector<int>& vals = values[root];

            sort(idx.begin(), idx.end());
            sort(vals.begin(), vals.end());

            for (int i = 0; i < idx.size(); i++) {
                ans[idx[i]] = vals[i];
            }
        }

        return ans;
    }
};