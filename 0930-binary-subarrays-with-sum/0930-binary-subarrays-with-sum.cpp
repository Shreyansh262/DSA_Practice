class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return isMost(nums,goal) - isMost(nums,goal-1);
    }
    int isMost(vector<int>& nums,int goal){
        int left = 0,right = 0,currSumm = 0,ans = 0;
        while(right<nums.size()){
            currSumm += nums[right];

            while(currSumm>goal && left<=right){
                currSumm -= nums[left];
                left++;
            }

            ans += (right-left + 1);
            right++;
        }
        return ans;
    }
};



























// unordered_map<int,int> cont;
        // cont[0]=0;
        // int currSum=0;
        // int ans = 0,x = 1,j=1;
        // for(auto i : nums){
        //     currSum+=i;
        //     if(cont.find(currSum-goal)!=cont.end()){
        //         ans++;
        //     }
        //     while(currSum>goal){
        //         currSum-=nums[j-1];
        //         j++;
        //     }
        //     cont[x] = currSum;
        //     x++;
        // }
        // return ans;