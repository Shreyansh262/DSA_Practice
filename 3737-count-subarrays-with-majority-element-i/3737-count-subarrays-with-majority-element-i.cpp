class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans =0;
        for(int i =0;i<nums.size();i++){
            int num = 0;
            for(int j = i;j<nums.size();j++){
                if(nums[j]==target){
                    num++;
                }
                if(num>(j-i+1)/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};