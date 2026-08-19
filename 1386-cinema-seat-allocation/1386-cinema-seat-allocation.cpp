class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int i = 0;
        int m = rs.size();
        int nc = 0;
        queue<int> q;
        sort(rs.begin(), rs.end());
        int ans = 0;
        while (i < m) {
            int cr = rs[i][0];
            while (i < m && rs[i][0] == cr) {
                q.push(rs[i][1]);
                i++;
            }
            nc++;
            int z = 2;
            bool s1 = true, s2 = true, s3 = true;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                if (s1 && x >= 2 && x <= 5) {
                    s1 = false;
                    z--;
                }
                if (s2 && x >= 6 && x <= 9) {
                    s2 = false;
                    z--;
                }
                if (x >= 4 && x <= 7)
                    s3 = false;
            }
            if (!s1 && !s2 && s3)
                z = 1;
            ans += z;
        }
        ans += 2 * (n - nc);
        return ans;
    }
};