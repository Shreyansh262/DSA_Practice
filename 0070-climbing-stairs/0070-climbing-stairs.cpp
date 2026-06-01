class Solution {
public:

    int climbStairs(int n) {
        //Tabulization + space
        int prev,prev2;
        prev=1;
        prev2=1;
        int curri = 1;
        for(int i = 2;i<=n;i++){
            curri = prev+prev2;
            prev2 = prev;
            prev = curri;
        }
        return curri;
        //Tabulization
        // vector<int> a(n+1,-1);
        // a[0]=1;
        // a[1]=1;
        // for(int i = 2;i<=n;i++){
        //     a[i] = a[i-1]+a[i-2];
        // }
        // return a[n];
    }
    //memoization
    // int f(int n, vector<int>& x) {
    //     if (n == 0) return 1;
    //     if (n == 1) return 1;
    //     if (x[n] != -1) return x[n];
    //     int left = f(n - 1, x);
    //     int right = f(n - 2, x);
    //     x[n] = left + right;
    //     return x[n];
    // }
};