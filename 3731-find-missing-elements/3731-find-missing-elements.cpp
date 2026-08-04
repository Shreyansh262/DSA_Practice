class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini,maxi;
        bool present[101] = {false};
        mini = *min_element(nums.begin(),nums.end());
        maxi = *max_element(nums.begin(),nums.end());
        vector<int>ans;
        for (int num : nums) {
            present[num] = true;
        }
        for (int i = mini + 1; i < maxi; i++) {
            if (!present[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};