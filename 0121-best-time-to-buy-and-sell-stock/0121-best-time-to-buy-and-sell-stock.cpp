class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxmm = 0 , bbd = prices[0];
        for(int i : prices){
            if(i>bbd){
                maxmm = max(maxmm , i-bbd);
            }
            else{
                bbd = i;
            }
        }
        return maxmm;
    }
};