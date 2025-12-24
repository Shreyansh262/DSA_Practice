class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1,f,w= INT_MAX,min_index;
        if (nums.size() > 1) {
            for (int i = nums.size() - 1; i > 0; i--) {
                if (nums[i] > nums[i - 1]) {
                    k = i - 1;
                    break;
                }
            }
            if (k == -1) {
                sort(nums.begin(), nums.end());
            } else {
                for (int j = k + 1; j < nums.size(); j++) {
                    if (nums[j] > nums[k]) {
                        f = min(w, nums[j]);
                        if (f != w) {
                            w = f;
                            min_index = j;
                        }
                    }
                }
                swap(nums[k], nums[min_index]);
                sort(nums.begin() + k + 1, nums.end());
            }
        }
    }
};