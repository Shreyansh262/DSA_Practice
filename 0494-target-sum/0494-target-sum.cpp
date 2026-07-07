class Solution {
public:
    int canPartition(int ind, vector<int>& nums, int target) {

        if (ind == nums.size()) {
            if (target == 0)
                return 1;
            else
                return 0;
        }
        int notpick = canPartition(ind + 1, nums, target);
        int pick = 0;
        if (nums[ind] <= target) {
            pick = canPartition(ind + 1, nums, target - nums[ind]);
        }
        return pick + notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum - target) % 2)
            return 0;
        int x = (sum - target) / 2;
        return canPartition(0, nums, x);
    }
};