class Solution {
public:
    int sum(vector<int>&cnt){
        int s = 0;
        for(int i : cnt){
            s+=i;
        }
        return s;
    }
    int solve(int i,int k,vector<int>&nums,vector<int>&cnt){
        if(i==nums.size() && sum(cnt)==0) return 0;
        else if(i==nums.size() && sum(cnt)>0) return 1;
        int nt = solve(i+1,k,nums,cnt);
        int t = 0;
        if(nums[i]<k||cnt[nums[i]-k]==0){
            cnt[nums[i]]++;
            t = solve(i+1,k,nums,cnt);
            cnt[nums[i]]--;
        }
        return nt+t;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        vector<int>cnt(nums[i]+1,0);
        int ans = solve(0,k,nums,cnt);
        return ans;
    }
};