class Solution {
public:
    int smallestNumber(int num, int t) {
        
        int ans;
        while (true){
            int n = num;
            int x = n%10;
            n/=10;
            int y = n%10;
            n/=10;
            int z = n%10;
            n/=10;
            int mul;
            if(z!=0){
                mul = x*y*z;
            }
            else if(y!=0){
                mul = x*y;
            }
            else{
                mul = x;
            }
            if(mul%t==0){
                ans = num;
                break;
            }
            num++;
        }
        return ans;
    }
};