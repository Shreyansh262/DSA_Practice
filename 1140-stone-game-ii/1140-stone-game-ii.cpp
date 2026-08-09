class Solution {
public:
    int solve(int ind, int M, vector<int>& piles,vector<vector<int>>&dp) {
        if ((ind + 2 * M) >= piles.size()) {
            int Z = 0;
            for (int i = ind; i < piles.size(); i++) {
                Z += piles[i];
            }
            return Z;
        }
        if(dp[ind][M]!= INT_MIN) return dp[ind][M];
        int delta = 0;
        int maxProf = INT_MIN;
        for (int i = 1; i <= (2 * M); i++) {
            int temp_M = max(M, i);
            int Z = 0;
            for (int j = 0; j < i; j++) {
                Z += piles[ind + j];
            }
            delta = Z - solve(ind + i, temp_M, piles,dp);
            maxProf = max(maxProf, delta);
        }
        return dp[ind][M] = maxProf;
    }
    int stoneGameII(vector<int>& piles) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size()+1,INT_MIN));
        int AliceGain = solve(0, 1, piles,dp);
        return (sum + AliceGain) / 2;
    }
};