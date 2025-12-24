class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int x = 0,f=0;
        vector <int> ans;
        for (int i = 0; i<nums.size();i++){
            x = nums[i];
            f=0;
            for(int j = 0; j<nums.size();j++){
                if(nums[j]< x){
                    f++;
                }
            }
            ans.push_back(f);
        }
        return ans;
    }
};