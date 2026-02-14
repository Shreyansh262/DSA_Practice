class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int req = pos(query_row, query_glass);
        unordered_map<int, double> extra;
        if (poured == 0)
            return 0.0;
        extra[1] = max(0.0,poured - 1.0);
        if (query_row == 0) 
            return min(1.0, (double)poured);
        for (int i = 1; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double curr;
                if (j == 0)
                    curr = extra[pos(i - 1, 0)] / 2;
                else if (j == i)
                    curr = extra[pos(i - 1, i - 1)] / 2;
                else
                    curr = extra[pos(i - 1, j - 1)] / 2 + extra[pos(i - 1, j)] / 2;

                if (pos(i, j) == req) {
                    return min(1.0,curr);
                }
                extra[pos(i, j)] = max(0.0, curr - 1);
            }
        }
        return 0.0;
    }
    int pos(int i, int j) { return ((i * (i + 1) / 2) + j + 1); }
};