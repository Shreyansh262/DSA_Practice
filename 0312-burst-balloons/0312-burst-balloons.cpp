class Solution {
public:
    int help(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int ind = i;ind<=j;ind++){
            int m = nums[i-1]*nums[j+1]*nums[ind] + help(i,ind-1,nums,dp)+help(ind+1,j,nums,dp);
            maxi = max(maxi,m);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return help(1, n-2, nums, dp);
    }
};