class Solution {
public:
    void X(int i, vector<int>& nums, vector<int>& ds,
           vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        X(i + 1, nums, ds, ans);
        ds.pop_back();
        X(i + 1, nums, ds, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        X(0, nums, ds, ans);
        return ans;
    }
};