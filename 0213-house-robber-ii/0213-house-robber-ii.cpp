class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        if(nums.size()==2){return max(nums[0],nums[1]);}
        vector<int> dp(nums.size(), -1);
        int left = cash(nums.size()-1,true,nums,dp);
        vector<int> de(nums.size(), -1);
        int right = cash(nums.size()-2,false,nums,de);
        return max(left,right);
    }
    int cash(int pos,bool cy ,vector<int>& nums, vector<int>& db){
        if(pos <0) return 0;
        if(pos == 0 && cy) return nums[0]-nums[nums.size()-1];
        if(pos == 0 || pos == 1){return nums[pos];}
        if(db[pos]!=-1) return db[pos];
        int left = cash(pos - 2,cy,nums,db) + nums[pos];
        int right = cash(pos - 3,cy,nums,db)+ nums[pos];
        return db[pos] = max(left,right);
    }
};        