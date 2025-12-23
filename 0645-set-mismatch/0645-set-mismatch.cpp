class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<int> check;

        for (int i = 1; i <= nums.size(); i++) {
            check.push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            auto it = find(check.begin(), check.end(), nums[i]);
            if (it != check.end()) {
                check.erase(it);
            } else {
                ans.push_back(nums[i]); // duplicate
            }
        }

        ans.push_back(check[0]); // missing
        return ans;
    }
};
