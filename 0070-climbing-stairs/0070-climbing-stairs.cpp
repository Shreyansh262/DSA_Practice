class Solution {
public:
    int climbStairs(int n) {
        vector<int> a(n+1,-1);
        int ans = f(n,a);
        return ans;
    }
    int f(int n, vector<int>& x) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (x[n] != -1) return x[n];
        int left = f(n - 1, x);
        int right = f(n - 2, x);
        x[n] = left + right;
        return x[n];
    }
};