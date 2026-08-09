class Solution {
public:
    int solve(int ind, int M, vector<int>& piles,vector<vector<int>>&dp,vector<int>&suffix) {
        int n = piles.size();
        if(ind>=n) return 0;
        if ((ind + 2 * M) >= n) return (suffix[ind]);
        if(dp[ind][M]!= INT_MIN) return dp[ind][M];
        int delta = 0;
        int maxProf = INT_MIN;
        for (int i = 1; i <= (2 * M); i++) {
            int temp_M = max(M, i);
            int Z = suffix[ind] - suffix[ind + i];
            delta = Z - solve(ind + i, temp_M, piles,dp,suffix);
            maxProf = max(maxProf, delta);
        }
        return dp[ind][M] = maxProf;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1,INT_MIN));
        vector<int>suffix(n+1,0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = piles[i] + suffix[i + 1];
        int AliceGain = solve(0, 1, piles,dp,suffix);
        return (suffix[0] + AliceGain) / 2;
    }
};