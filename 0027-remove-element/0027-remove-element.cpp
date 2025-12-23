class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>* ptr = &nums;
        int k=0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Place non-val element at position k
                k++; // Move k forward
            }
        }
        
        return k;
        
    }
};