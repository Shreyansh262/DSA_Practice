class Solution {
public:
    int comSubseq(int i,int j,string& s1,string& s2, vector<vector<int>>& dp){
        if(i==s1.size()||j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x1 = comSubseq(i,j+1,s1,s2,dp);
        int x2 = comSubseq(i+1,j,s1,s2,dp);
        int x3 = 0;
        if(s1[i]==s2[j]){
            x3 = 1 + comSubseq(i+1,j+1,s1,s2,dp);
        }
        return dp[i][j] = max(x1,max(x2,x3));
    }
    int minInsertions(string s) {
        string s2 = s;
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        reverse(s2.begin(),s2.end());
        dp[n-1][n-1] = comSubseq(0,0,s,s2,dp);
        return n-dp[n-1][n-1];
    }
};