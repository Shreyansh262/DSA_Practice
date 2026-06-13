class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans = fibo(n,dp);
        return ans;
    }
    int fibo(int n,vector<int>& dp){
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(dp[n]!= -1) return dp[n];
        else dp[n] = fib(n-1)+fib(n-2);
        return dp[n];
    }
};