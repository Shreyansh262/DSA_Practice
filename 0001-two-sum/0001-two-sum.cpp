#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j ,sum = 0;
        vector<int>vec ;
        for(i;i<size(nums);i++){
            for(j=i+1;j<size(nums);j++){
                sum = nums[i] + nums[j];
                if(sum==target) {
                    vec = {i,j};
                    return vec;
                }
            } 
        }
        return vec;
    }
};