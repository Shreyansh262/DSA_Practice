using d = double;
class Solution {
public:
    int solve(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind < 0) {
            if (amt == 0)
                return 1;
            else
                return 0;
        }
        if (dp[ind][amt] != -1)
            return dp[ind][amt];
        int notP = solve(ind - 1, amt, coins, dp);
        int pick = 0;

        if (coins[ind] <= amt) {
            pick = solve(ind, amt - coins[ind], coins, dp);
        }
        return dp[ind][amt] = pick + notP;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<d>> dp(n, vector<d>(amount + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int ind = 0; ind < n; ind++) {
            for (int amt = 1; amt <= amount; amt++) {
                d notP = 0;
                if (ind > 0) {
                    notP = dp[ind - 1][amt];
                }
                d pick = 0;

                if (coins[ind] <= amt) {
                    pick = dp[ind][amt - coins[ind]];
                }
                dp[ind][amt] = pick + notP;
            }
        }
        return (int)dp[n - 1][amount];
    }
};