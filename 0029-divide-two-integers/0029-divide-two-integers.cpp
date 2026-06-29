class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isNeg = (dividend<0)^(divisor<0);
        long long absdividend = abs((long long)dividend);
        long long absdivisor = abs((long long)divisor);
        long long quotient = 0;

        while(absdividend >= absdivisor){
            long long temp = absdivisor,multiple = 1;
            while(absdividend>=(temp<<1)){
                temp <<= 1;
                multiple <<= 1;
            }
            absdividend -= temp;
            quotient += multiple;
        }
        return isNeg ? -quotient:quotient;
    }
};