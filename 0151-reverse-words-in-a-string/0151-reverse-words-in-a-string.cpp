class Solution {
public:
    string reverseWords(string s) {
        s = " " + s;
        string x = "";
        string k = "";
        int sp = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isalnum(s[i])) {
                x = s[i] + x;
                sp = 0;
            } else if (sp == 0 && x != "") {
                k = k + " " + x;
                x = "";
                sp = 1;
            } else
                continue;
        }
        k = k.substr(1, k.size() - 1);
        return k;
    }
};