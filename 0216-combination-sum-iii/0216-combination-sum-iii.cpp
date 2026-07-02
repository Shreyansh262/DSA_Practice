class Solution {
public:
    void X(int i,vector<int>& nums, vector<int>& ds,int n,int k, vector<vector<int>>& ans) {
        if(k==0){
            if (n==0){
                ans.push_back(ds);
            }
            return;
        }
        if(i>8){return;}
        ds.push_back(nums[i]);
        X(i+1,nums,ds,(n-nums[i]),k-1,ans);
        ds.pop_back();
        X(i+1,nums,ds,n,k,ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        X(0, nums, ds,n,k, ans);
        return ans;
    }
};
