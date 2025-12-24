class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans (nums.size(),0);
        vector<int> ans2;

        for(int x = 0; x < nums.size();x++){
            ans[nums[x]-1]++;
        }
        for(int x = 0; x < nums.size();x++){
            if(ans[x] == 0){
                ans2.push_back(x+1);
            }

        }
        return ans2;
    }
};