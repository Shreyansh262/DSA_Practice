class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, sum = 0;
        string s;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i = 0;
        while (i < a.size() && i < b.size()) {
            if (a[i] - '0' && b[i] - '0') {
                if (carry) {
                    s.push_back('1');
                } else {
                    s.push_back('0');
                }
                carry = 1;
            }else if (!(a[i] - '0') && !(b[i] - '0')) {
                if (carry) {
                    s.push_back('1');
                } else {
                    s.push_back('0');
                }
                carry = 0;
            } else {
                if (carry) {
                    s.push_back('0');
                    carry = 1;
                } else {
                    s.push_back('1');
                    carry = 0;
                }
            }
            i++;
        }
        while (i < a.size()) {
            if (a[i] - '0') {
                if (carry) {
                    s.push_back('0');
                    carry = 1;
                } else {
                    s.push_back('1');
                    carry = 0;
                }
            } else {
                if (carry) {
                    s.push_back('1');
                    carry = 0;
                } else {
                    s.push_back('0');
                }
            }
            i++;
        }
        while (i < b.size()) {
            if (b[i] - '0') {
                if (carry) {
                    s.push_back('0');
                    carry = 1;
                } else {
                    s.push_back('1');
                    carry = 0;
                }
            } else {
                if (carry) {
                    s.push_back('1');
                    carry = 0;
                } else {
                    s.push_back('0');
                }
            }
            i++;
        }
        if (carry){
            s.push_back('1');
        }
        reverse(s.begin(),s.end());
        return s;
    }
};