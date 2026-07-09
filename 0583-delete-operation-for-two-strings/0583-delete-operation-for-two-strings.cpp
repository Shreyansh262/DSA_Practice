class Solution {
public:
    int solve(int i, int j,string& word1, string& word2,vector<vector<int>>& dp){
        if(i==word1.size()||j==word2.size()){
            if(i<word1.size()) return word1.size()-i;
            else if(j<word2.size()) return word2.size()-j;
            else return 0;
        }
        int op;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            op = solve(i+1,j+1,word1,word2,dp);
        } else{
            int x1 = 1+solve(i+1,j,word1,word2,dp);
            int x2 = 1+solve(i,j+1,word1,word2,dp);
            op = min(x1,x2);
        }
        return dp[i][j]=op;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,word1,word2,dp);
    }
};