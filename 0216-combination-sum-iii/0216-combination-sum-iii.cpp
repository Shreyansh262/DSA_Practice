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
// class Solution {
// public:
//     vector<vector<int>> res;
//     void backtrack(int k, int target, int start, vector<int>& path) {
//         if (target == 0 && k == 0) {
//             res.push_back(path);
//             return;
//         }
//         for (int i = start; i <= 9; ++i) {
//             if (i > target || k <= 0) break;
//             path.push_back(i);
//             backtrack(k - 1, target - i, i + 1, path);
//             path.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<int> path;
//         backtrack(k, n, 1, path);
//         return res;
//     }
// };
