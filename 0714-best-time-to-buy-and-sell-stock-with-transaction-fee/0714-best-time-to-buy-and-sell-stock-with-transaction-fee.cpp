class Solution {
public:
    int x(int ind, bool buy,int fees,vector<int>& prices,vector<vector<int>>& dp){

        if(ind == prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            int x1 = -prices[ind] + x(ind+1,!buy,fees,prices,dp);
            int x2 = x(ind+1,buy,fees,prices,dp);
            profit = max(x1,x2);
        }else{
            int x1 = prices[ind] + x(ind+1,!buy,fees,prices,dp)-fees;
            int x2 = x(ind+1,buy,fees,prices,dp);
            profit = max(x1,x2);
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices,int fees) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return x(0,true,fees,prices,dp);
    }
};