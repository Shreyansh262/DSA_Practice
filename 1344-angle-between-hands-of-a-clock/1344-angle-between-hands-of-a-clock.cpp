class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = 360;
        double m = 360;
        m = (m/60)*minutes;
        h = (((h/12)*hour) + (30)*(minutes/60.0));
        if(h>360) h = h - 360;
        double ans = abs(m-h);
        if(ans>180.0) ans = 360 - ans;
        return ans;
    }
};