class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> y = nums;
        sort(y.begin(),y.end());
        bool w ;
        for(int x = 0; x<nums.size();x++){
            w = true;
            for(int i = 0;i<nums.size();i++){
                if(y[i] != nums[(i+x)%nums.size()]){
                    w = false;
                    break;
                }
            }
            if(w == true){
                return true;
            }

        }
        return false;
    }
};