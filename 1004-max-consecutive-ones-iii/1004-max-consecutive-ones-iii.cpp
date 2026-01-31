class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, maxans = 0;
        int l = 0;
        for (j = 0;j< nums.size();j++){
            if(nums[j]==0){
                l++;
            }
            if(l>k){
                if(nums[i]==0){
                    l--;
                }
                i++;
            }
            maxans = max(maxans,j-i+1);
        }
        return maxans;
    }
};
//     if(l == k){
//         i = j;
//         l--;
//         ans++;
//     }
//     else if (l == 0){
//         maxans = max(maxans,ans);
//         i++;
//         if(nums[i] == 1) {l=1;}
//         else {l = 0;
//         ans = j-i+1;}
//     }
//     else {
//         l--;
//         ans++;
//     }