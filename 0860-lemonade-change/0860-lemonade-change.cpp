class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, t = 0, tw = 0;
        for (auto it = bills.begin(); it != bills.end(); it++) {
            if (*it == 5)
                f++;
            else if (*it == 10) {
                if(f==0) return false;
                f--;
                t++;
            } else {
                if (t > 0 && f > 0) {
                    tw++;
                    t--;
                    f--;
                } else if (f >= 3) {
                    f -= 3;
                    tw++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};