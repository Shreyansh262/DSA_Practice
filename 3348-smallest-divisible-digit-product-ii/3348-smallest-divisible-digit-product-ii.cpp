class Solution {
public:
    typedef long long ll;
    string helper(ll req, int len) {
        string str;
        for (int i = 9; i >= 2; i--) {
            while (req % i == 0) {
                str.push_back(i + '0');
                req /= i;
            }
        }
        while (str.length() < len) {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string smallestNumber(string num, long long t) {
        long long x = t;
        for (int i : {2, 3, 5, 7}) {
            while (x % i == 0) {
                x = x / (ll)i;
            }
        }
        if (x != 1)
            return "-1";
        int n = num.length();
        vector<ll> req(n + 1, t);
        for (int i = 1; i <= n; i++) {
            int digit = num[i - 1] - '0';
            if (digit == 0)
                break;

            req[i] = req[i - 1] / gcd(req[i - 1], (ll)digit);
        }
        if (req[n] == 1)
            return num;
        int zeroPos = num.find('0');
        int zeroInd = n - 1;
        if (zeroPos != -1) {
            zeroInd = zeroPos;
        }
        for (int i = zeroInd; i >= 0; i--) {
            ll required = req[i];
            int fS = n - i - 1;
            for (int d = (num[i] - '0')+1; d <= 9; d++) {

                ll temp = required / (gcd(required, (ll)d));
                string w = helper(temp, fS);
                if (w.length() == fS) {
                    return num.substr(0, i) + char(d + '0') + w;
                }
            }
        }
        return helper(t, n + 1);
    }
};