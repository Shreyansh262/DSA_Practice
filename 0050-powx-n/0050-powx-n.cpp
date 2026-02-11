class Solution {
public:
    double myPow(double x, long int n) {
        // double ans = 1;
        // if(n < 0){
        //     x = 1/x;
        //     n = -1*n;
        // }
        // while(n>0){
        //     if(n%2 == 1){
        //         ans *= x;
        //     }
        //     x *= x;
        //     n/= 2;
        // }
        // return ans;
        if (n < 0) {
            n *= -1;
            x = 1 / x;
        }
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x, n - 1);
    }
};