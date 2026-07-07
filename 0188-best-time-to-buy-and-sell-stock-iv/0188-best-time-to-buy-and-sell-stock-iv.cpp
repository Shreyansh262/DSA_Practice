class Solution {
public:
    int x(int ind, int trans,int k, vector<int>& prices, vector<vector<int>>& dp) {

        if (ind == prices.size())
            return 0;
        if (trans == 2*k)
            return 0;
        if (dp[ind][trans] != -1)
            return dp[ind][trans];
        int profit = 0;
        if (trans % 2 == 0) {
            int x1 = -prices[ind] + x(ind + 1, trans + 1,k, prices, dp);
            int x2 = x(ind + 1, trans,k, prices, dp);
            profit = max(x1, x2);
        } else {
            int x1 = prices[ind] + x(ind + 1, trans + 1, k,prices, dp);
            int x2 = x(ind + 1, trans,k, prices, dp);
            profit = max(x1, x2);
        }
        return dp[ind][trans] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        dp[n-1][2*k-1] = x(0, 0, k,prices, dp);
        return dp[n-1][2*k-1];
    }
};