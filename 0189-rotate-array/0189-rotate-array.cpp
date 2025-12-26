class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> var(nums.size());
        for(int i = 0; i< nums.size();i++){
            var[(i+k)%nums.size()] = nums[i];
        }
        nums = var;
    }
};