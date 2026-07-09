class Solution {
public:
    // string superseq(int i, int j, string& str1, string& str2,vector<vector<string>>& dp) {
    //     if (i == str1.size() || j == str2.size()) {
    //         string ans;
    //         while (i < str1.size()) {
    //             ans.push_back(str1[i]);
    //             i++;
    //         }
    //         while (j < str2.size()) {
    //             ans.push_back(str2[j]);
    //             j++;
    //         }
    //         return ans;
    //     }
    //     if (dp[i][j] != "")
    //         return dp[i][j];
    //     string ans1, ans2;
    //     if (str1[i] == str2[j]) {
    //         return dp[i][j] = str1[i] + superseq(i + 1, j + 1, str1, str2, dp);
    //     }

    //     ans1 = str1[i] + superseq(i + 1, j, str1, str2, dp);
    //     ans2 = str2[j] + superseq(i, j + 1, str1, str2, dp);

    //     if (ans1.size() < ans2.size())
    //         dp[i][j] = ans1;
    //     else
    //         dp[i][j] = ans2;
    //     return dp[i][j];
    // }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
        int m = str1.size(), n = str2.size();

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string ans="";
        int i = m-1,j=n-1;
        while(i>=0&&j>=0){
           if (str1[i] == str2[j]) {
                ans += str1[i];
                i--; j--; 
            } else if (dp[i][j+1] > dp[i+1][j]) {
                ans += str1[i];
                i--;
            } else {
                ans += str2[j];
                j--;
            }
        }
        while (i >= 0) { ans += str1[i]; i--; }
        while (j >= 0) { ans += str2[j]; j--; }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};