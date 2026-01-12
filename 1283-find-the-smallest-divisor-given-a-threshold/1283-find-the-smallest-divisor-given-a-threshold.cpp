class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1,end = maxEle(nums);
        int ans;
        while(st<=end){
            int mid = end - (end - st)/2;
            if(sumCalc(nums,mid) <= threshold){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
    int sumCalc(vector<int>& nums, int k){
        int sum = 0;
        for(int &i : nums){
            sum += (i+k-1)/k;
        }
        return sum;
    }
    int maxEle(vector<int>& nums){
        int val = INT_MIN;
        for(int &i : nums) val = max(val,i);
        return val;
    }
};