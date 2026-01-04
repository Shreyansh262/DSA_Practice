class Solution {
public:
    int bs(vector<int>& nums, int st, int end, int target) {
        int mid = end - (end - st) / 2;
        if (nums[mid] == target)
            return mid;
        if (st >= end) {
            return -1;
        } else if (nums[mid] > target) {
            if (nums[end] > nums[mid])
                return bs(nums, st, mid-1, target);
            else if (nums[st] <= target)
                return bs(nums, st, mid-1, target);
            else
                return bs(nums, mid+1, end, target);
        } else if (nums[mid] < target) {
            if (nums[mid] >= nums[st])
                return bs(nums, mid+1, end, target);
            else if (nums[end] < target)
                return bs(nums, st, mid-1, target);
            else
                return bs(nums, mid+1, end, target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        return bs(nums, st, end, target);
    }
};