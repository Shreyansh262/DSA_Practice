class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1] = solve(m-1,n-1,dp);
        return dp[m-1][n-1];
    }
    int solve(int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(i==0&&j==0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i-1,j,dp);
        int left = solve(i,j-1,dp);
        dp[i][j] = up+left;
        return dp[i][j];
    }
};