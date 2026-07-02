class Solution {
public:
    void X(vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans,
           int ind, int target, int n) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        for(int i = ind;i<n;i++) {
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            X(candidates, ds, ans, i+1, target - candidates[i], n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        X(candidates, ds, ans, 0, target, n);
        return ans;
    }
};