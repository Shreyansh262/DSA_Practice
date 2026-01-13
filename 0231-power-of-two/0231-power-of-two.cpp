class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        while(n>0){
            
            int x = n%2;
            n/=2;
            if(x != 0 && n != 0){
                return false;
            }
        }
        return true;
    }
};