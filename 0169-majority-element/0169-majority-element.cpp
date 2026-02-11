class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int f = 0 , t = nums[0] ;
        for(int i : nums){
            if(i == t){
                f++;
            }
            else{
                f--;
            }
            if(f==0){
                t = i;
                f++;
            }

        }
    return t;
    }
};