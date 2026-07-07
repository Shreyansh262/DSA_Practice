class Solution {
public:
    int solve(int ind, int amt, vector<int>& coins,vector<vector<int>>&dp){
        if(ind <0){
            if(amt == 0) return 1;
            else return 0;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int notP = solve(ind-1,amt,coins,dp);
        int pick = 0;

        if(coins[ind]<=amt){
            pick = solve(ind,amt-coins[ind],coins,dp);
        }
        return dp[ind][amt] = pick + notP;
    }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        dp[n-1][amount] = solve(n-1,amount,coins,dp);
        return dp[n-1][amount];
    }
};