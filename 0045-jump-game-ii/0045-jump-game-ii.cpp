class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0,right = 0,jump = 0;
        while(right<nums.size() && left<=right){
            if(right==nums.size()-1) return jump;
            int maxpos = 0;
            for(int i = left;i<=right;i++){
                maxpos = max(maxpos,i+nums[i]);
            }
            left = right+1;
            right = maxpos;
            jump++;
            
        }
        return jump;

    }
};