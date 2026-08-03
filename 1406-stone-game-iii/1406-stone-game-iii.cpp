class Solution {
public:
    const int m = -1e5;
    int solve(int i,vector<int>& stoneValue,vector<int>&dp){
        if(i>=stoneValue.size()) return 0;
        if(dp[i]!=m) return dp[i];
        int x = stoneValue[i] - solve(i+1,stoneValue,dp);
        int y = m,z = m;
        if(i+1<stoneValue.size()){
            y = stoneValue[i] + stoneValue[i+1] - solve(i+2,stoneValue,dp);
        }
        if(i+2<stoneValue.size()){
            z = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3,stoneValue,dp);
        }

        return dp[i]=max(x,max(y,z));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        vector<int>dp(stoneValue.size(),m);
        int del = solve(0,stoneValue,dp);
        if(del>0) return "Alice";
        else if(del<0) return "Bob";
        else return "Tie";
    }
};