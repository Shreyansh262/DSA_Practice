class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < half)
                    q1++;
                else
                    q2++;
            } else {
                if (i < half)
                    diff += num[i] - '0';
                else
                    diff -= num[i] - '0';
            }
        }
        if ((q1 + q2) % 2 == 1)
            return true;

        return diff != 9 * (q2 - q1) / 2;
    }
};