class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> evn(n),odd(n);
        vector<int> ans(2*n);
        for(int i =0;i<n;i++){
            evn[i] = nums[i];
            odd[i] = nums[i+n];
            ans[2*i] = evn[i];
            ans[2*i+1] = odd[i];
        }
        return ans;
    }

};