class Solution {
public:
    int solve(int ind, vector<int>& nums, int target,vector<vector<int>>& dp) {
        if (ind == 0) {
            if (nums[0] == target)
                return 1;
            else return 0;
        }
        if(dp[ind][target]!= -1) return dp[ind][target];
        bool notTake = solve(ind - 1, nums, target,dp);
        bool take = false;
        if (nums[ind] <= target)
            take = solve(ind - 1, nums, target - nums[ind],dp);
        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for (int i : nums) {
            totSum += i;
        }
        if(totSum%2) return false;
        int target = totSum / 2;
        vector<vector<int>>dp(nums.size(),vector<int>(target + 1,-1));
        return solve(nums.size() - 1, nums, target,dp);
    }
};