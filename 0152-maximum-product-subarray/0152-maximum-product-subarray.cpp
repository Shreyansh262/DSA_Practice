class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int minProd = nums[0];
        int maxProd = nums[0];
        for(int i = 1;i < nums.size();i++){
            int curr = nums[i];
            if(curr<0){
                swap(minProd,maxProd);
            }
            minProd = min(curr,minProd*curr);
            maxProd = max(curr,maxProd*curr);

            res = max(res,maxProd);
        }
        return res;
    }
};