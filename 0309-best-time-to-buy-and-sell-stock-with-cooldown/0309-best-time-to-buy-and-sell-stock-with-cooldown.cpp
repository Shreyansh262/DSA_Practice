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
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return x(0,true,prices,dp);
    }
};