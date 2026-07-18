class Solution {
public:
    int mySqrt(int x) {
        long long i;
        for(i = 1;i*i<=x;i++){}
        return i-1;
    }
};