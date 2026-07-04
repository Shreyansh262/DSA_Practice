class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // dp[m-1][n-1] = solve(m-1,n-1,dp);
        // dp[0][0] = 1;
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }
                int left = 0, up = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = left + up;
            }
            prev = temp;
        }
        return prev[n - 1];
    }
    // int solve(int i,int j,vector<vector<int>>& dp){
    //     if(i<0 || j<0) return 0;
    //     if(i==0&&j==0) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = solve(i-1,j,dp);
    //     int left = solve(i,j-1,dp);
    //     dp[i][j] = up+left;
    //     return dp[i][j];
    // }
};