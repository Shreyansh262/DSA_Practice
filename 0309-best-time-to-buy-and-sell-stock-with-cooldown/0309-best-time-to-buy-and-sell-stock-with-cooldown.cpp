class Solution {
public:
    int x(int ind, bool buy,vector<int>& prices,vector<vector<int>>& dp){

        if(ind >= prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            int x1 = -prices[ind] + x(ind+1,!buy,prices,dp);
            int x2 = x(ind+1,buy,prices,dp);
            profit = max(x1,x2);
        }else{
            int x1 = prices[ind] + x(ind+2,!buy,prices,dp);
            int x2 = x(ind+1,buy,prices,dp);
            profit = max(x1,x2);
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind = n-1;ind>=0;ind--){

            int x1 = -prices[ind] + dp[ind+1][0];
            int x2 = dp[ind+1][1];
            dp[ind][1] = max(x1,x2);

            x1 = prices[ind] + dp[ind+2][1];
            x2 = dp[ind+1][0];
            dp[ind][0] = max(x1,x2);
        }
        return dp[0][1];
    }
};