class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp;
        vector<int> temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i = 0;i<n;i++){
            if(i!=0) temp.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(robber(temp),robber(temp2));
    }
    int robber(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        int curr;
        for(int i = 1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int notTake = 0+prev;
            curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }


    // if(nums.size()==1){return nums[0];}
    //     if(nums.size()==2){return max(nums[0],nums[1]);}
    //     vector<int> dp(nums.size(), -1);
    //     int left = cash(nums.size()-1,nums,dp);
    //     int right = cash(nums.size()-2,nums,dp);
    //     return max(left,right);
    // }
    // int cash(int pos,vector<int>& nums, vector<int>& db){
    //     if(pos <0) return 0;
    //     if(pos == 0 || pos == 1){return nums[pos];}
    //     if(db[pos]!=-1) return db[pos];
    //     int left = cash(pos - 2,nums,db) + nums[pos];
    //     int right = cash(pos - 3,nums,db)+ nums[pos];
    //     return db[pos] = max(left,right);
};        