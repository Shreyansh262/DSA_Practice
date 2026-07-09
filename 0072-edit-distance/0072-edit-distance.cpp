class Solution {
public:
    int solve(int i,int j,string& word1, string& word2,vector<vector<int>>& dp){
        if(i<0||j<0){
            if(i>=0) return i+1;
            else if(j>=0) return j+1;
            else return 0;
        }
        if(dp[i][j]!= -1) return dp[i][j];
        if(word1[i]==word2[j]) {
            return dp[i][j] = solve(i-1,j-1,word1,word2,dp);
        }
        else{
            
            int m1 = 1+solve(i-1,j-1,word1,word2,dp);
            int m2 = 1+solve(i-1,j,word1,word2,dp);
            int m3 = 1+solve(i,j-1,word1,word2,dp);
            // cout<<i<<"      "<<j<<"::::::::\n";
            // cout<<m1<<" "<<m2<<" "<<m3<<" \n";
            return dp[i][j] = min(m1,min(m2,m3));
        }
        return 0;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(),n= word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)dp[i][0]=i;
        for(int i=1;i<=n;i++)dp[0][i]=i;
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    
                    int m1 = 1+dp[i-1][j-1];
                    int m2 = 1+dp[i][j-1];
                    int m3 = 1+dp[i-1][j];
                    dp[i][j] = min(m1,min(m2,m3));
                }
            }
        }
        
        return dp[m][n];
    }
};