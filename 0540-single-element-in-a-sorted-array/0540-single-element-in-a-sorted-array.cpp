class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //brute force
        int ans = 0;
        for(int i : nums){
            ans = ans^i;
        }
        return ans;
    }
};