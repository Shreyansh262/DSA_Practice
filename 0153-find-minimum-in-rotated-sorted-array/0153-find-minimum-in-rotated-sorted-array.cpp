class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        int mm = INT_MAX;
        while(low<=high){
            int mid = high - (high - low)/2;
            if(nums[mid]>nums[low]){
                mm = min(mm,nums[low]);
                low = mid+1;
            }else{
                mm = min(mm,nums[mid]);
                high = mid-1;
            }
        }
        return mm;
    }
};