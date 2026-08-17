class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {0, 0, 0};

        for (int x : stones) {
            c[x % 3]++;
        }

        int c0 = c[0];
        int c1 = c[1];
        int c2 = c[2];

        if (min(c1, c2) == 0) {
            return max(c1, c2) > 2 && c0 % 2 == 1;
        }

        return abs(c1 - c2) > 2 || c0 % 2 == 0;
    }
};