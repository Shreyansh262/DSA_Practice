class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1, mid;
        int posi = -1;
        while (st <= end) {
            mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                st = mid + 1;
                posi = mid + 1;
            } else {
                end = mid - 1;
                posi = mid;
            }

        }
        return posi;
    }
};