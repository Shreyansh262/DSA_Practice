class Solution {
public:
    int divide(int dividend, int divisor) {
        if((long long)dividend/divisor > INT_MAX) return INT_MAX;
        if((long long)dividend/divisor < INT_MIN) return INT_MIN;
        return dividend/divisor;
    }
};