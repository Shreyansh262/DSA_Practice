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
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,word1,word2,dp);
    }
};