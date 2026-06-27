class Solution {
public:
    int isMost(vector<int>& nums,int k){
        int left = 0,right = 0,currSumm = 0,ans = 0;
        while(right<nums.size()){
            currSumm += (nums[right]%2);

            while(currSumm>k){
                currSumm -= (nums[left]%2);
                left++;
            }
            ans += (right-left +1);
            right++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return isMost(nums,k) - isMost(nums,k-1);
    }
};