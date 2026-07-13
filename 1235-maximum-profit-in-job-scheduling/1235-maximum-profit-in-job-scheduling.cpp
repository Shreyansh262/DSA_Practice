class Solution {
public:
    int solve(int i,int n,vector<vector<int>>& jobs,vector<int>& dp){
        if(i == n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        //not pick
        int res = solve(i+1,n,jobs,dp);
        //pick
        int next_ind = n;
        //binary search to find index
        int high = n-1,low = i+1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(jobs[mid][0]>=jobs[i][1]){
                next_ind = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        res = max(res,jobs[i][2]+solve(next_ind,n,jobs,dp));
        return dp[i] = res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n,vector<int>(3,0));
        for(int i = 0;i<n;i++){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        vector<int>dp(n,-1);
        sort(jobs.begin(),jobs.end());
        dp[n-1] = solve(0,n,jobs,dp);
        return dp[n-1];
    }
};