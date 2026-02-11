class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0,j = 1;
        vector<int> rea(nums.size());
        for(int k : nums){
            if(k>=0){
                rea[i] = k;
                i+=2;
            }
            else{
                rea[j] = k;
                j+=2;
            }
        }
        return rea;
    }
};