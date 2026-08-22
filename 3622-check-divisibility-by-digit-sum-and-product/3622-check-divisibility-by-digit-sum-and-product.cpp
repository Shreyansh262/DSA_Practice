class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int temp = n;
        while(temp>0){
            int x = temp%10;
            sum += x;
            prod *= x;
            temp/=10;
        }
        if(prod+sum == 0) return false;
        else if(n%(prod+sum) == 0) return true;
        else return false;
    }
};