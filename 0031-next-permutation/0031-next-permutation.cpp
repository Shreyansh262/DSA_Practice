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
                for (int j = nums.size()-1; j>k; j--) {
                    if (nums[j] > nums[k]) {
                        swap(nums[k], nums[j]);
                        break;
                    }
                }
                sort(nums.begin() + k + 1, nums.end());
            }
        }
    }
};