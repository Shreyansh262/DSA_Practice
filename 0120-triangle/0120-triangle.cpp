class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int>prev(n,0);
        prev[0] = triangle[0][0];
        for(int i = 1;i<n;i++){
            vector<int>temp(n,0);
            for(int j = 0;j<=i;j++){
                int t1 = 1e7,t2 = 1e7;
                if(i-1>=j) t1 = triangle[i][j] + prev[j];
                if(j-1>=0) t2 = triangle[i][j] + prev[j-1];
                temp[j] = min(t1,t2);                
            }
            prev = temp;
        }
        int minp = 1e8;
        for(int i : prev){
            minp = min(minp,i);
        }
        return minp;
    }
        // int minp = 1e9;
        // for(int j = 0;j<n;j++){
        //     dp[n-1][j] = solve(triangle,dp,n-1,j);
        //     minp = min(minp,dp[n-1][j]);
        // }
    //     return minp;
    // }
    // int solve(vector<vector<int>>& triangle,vector<vector<int>>& dp, int i,int j){
    //     if(j<0 || j>i) return 1e7;
    //     if(i == 0) return triangle[0][0];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int t1 = triangle[i][j] + solve(triangle,dp,i-1,j);
    //     int t2 = triangle[i][j] + solve(triangle,dp,i-1,j-1);
    //     dp[i][j] = min(t1,t2);
    //     return dp[i][j];
    // }
};