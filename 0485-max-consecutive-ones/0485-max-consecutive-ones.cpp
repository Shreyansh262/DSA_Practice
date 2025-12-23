class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int f =0 , c = 1;
        int mf =0;
        for(int i:nums){
            if(i == c){
                f++;
                mf = max(f,mf);
            }
            else{
                f = 0;
            }

        }
        return mf;
    }
};