class Solution {
public:
    int maxProduct(int n) {
        int M = 0,sM = 0;
        int x;
        while(n>0){
            x = n%10;
            if(x>M){
                sM=M;
                M=x;

            }else if(x>sM){
                sM = x;
            }
            n = n/10;
        }
        return M*sM;
    }
};