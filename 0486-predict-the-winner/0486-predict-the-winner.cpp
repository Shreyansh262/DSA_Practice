class Solution {
    int memo[21][21];

    int maxDiff(vector<int>& nums, int st, int end) {
        if (st == end) return nums[st];
        if (memo[st][end] != -1) return memo[st][end];

        int takeStart = nums[st] - maxDiff(nums, st + 1, end);
        int takeEnd   = nums[end] - maxDiff(nums, st, end - 1);

        return memo[st][end] = max(takeStart, takeEnd);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return maxDiff(nums, 0, nums.size() - 1) >= 0;
    }
};