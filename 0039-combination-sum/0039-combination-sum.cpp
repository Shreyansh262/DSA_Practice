class Solution {
public:
    void X(vector<int>& candidates,vector<int>& ds,vector<vector<int>>& ans,int i,int target,int n){
        if(i>n){
            if(target == 0){
            ans.push_back(ds);}
            return;
        }
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            X(candidates,ds,ans,i,target-candidates[i],n);
            ds.pop_back();
        }
        X(candidates,ds,ans,i+1,target,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>ds;
        vector<vector<int>>ans;
        X(candidates,ds,ans,0,target,n-1);
        return ans;
    }
};