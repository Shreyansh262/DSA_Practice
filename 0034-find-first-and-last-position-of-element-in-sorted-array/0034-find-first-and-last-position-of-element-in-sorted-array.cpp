class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> ans = {-1,-1};
        int in = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == target && in == 0){
                in = 1;
                ans[0] = i;
            }
            if(nums[i] != target && in == 1){
                ans[1] = i-1;
                in = 0;
            }
        }
        if( in ==1 ) ans[1] = nums.size()-1;
        return ans;
    }
};