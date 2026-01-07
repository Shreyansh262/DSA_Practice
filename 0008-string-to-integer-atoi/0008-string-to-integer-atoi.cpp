class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        long num = 0;
        int x = 0;
        for (char& ch : s) {
            if (ch == ' '  && x == 0)
                continue;
            if (ch == '-' && x == 0) {
                sign = -1;
                x = 1;
            } else if (ch == '+' && x == 0) {
                sign = 1;
                x = 1;
            } else if ((int)ch >= 48 && (int)ch <= 57) {
                x = 1;
                int p = (int)ch- 48;
                if ((10 * num + p) >= INT_MAX && sign == 1) {
                    return INT_MAX;
                } else if (sign == -1 &&
                            sign * (10 * num + p) <= INT_MIN) {
                    return INT_MIN;
                } else
                    num = 10 * num +p;
            } else
                break;
        }
        return num * sign;
    }
};