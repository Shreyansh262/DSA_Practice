class Solution {
public:
    // int solve(int ind, vector<int>& nums, int target, vector<vector<int>>& dp) {
    //     if (ind == 0) {
    //         if (nums[0] == target)
    //             return 1;
    //         else
    //             return 0;
    //     }
    //     if (dp[ind][target] != -1)
    //         return dp[ind][target];
    //     bool notTake = solve(ind - 1, nums, target, dp);
    //     bool take = false;
    //     if (nums[ind] <= target)
    //         take = solve(ind - 1, nums, target - nums[ind], dp);
    //     return dp[ind][target] = take || notTake;
    // }
    bool canPartition(vector<int>& nums) {
        int totSum = 0;
        for (int i : nums) {
            totSum += i;
        }
        if (totSum % 2)
            return false;
        int target = totSum / 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
        if (nums[0] <= target)
            dp[0][nums[0]] = true;
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[i - 1][t];
                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1][t-nums[i]];
                dp[i][t] = take || notTake;
            }
        }
        return dp[nums.size() - 1][target];
    }
};