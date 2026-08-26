class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int ml = INT_MAX, mn = INT_MAX;
        while (s[i] != '1') {
            i++;
            if(i==s.size()) return "";
        }
        string ms = "";
        int j = i;
        int c = 1;
        while (j < s.size()) {
            while (c < k) {
                j++;
                while (s[j] != '1') {
                    j++;
                    if(j >= s.size()) return ms;
                }
                c++;
            }
            if (c == k) {
                if (j - i + 1 < ml) {
                    ml = j - i + 1;
                    ms = s.substr(i, j - i + 1);
                } else if (j - i + 1 == ml) {
                    string x = s.substr(i, j - i + 1);
                    if (x < ms) {
                        ms = x;
                    }
                }
                i++;
                c--;
                while (i < j && s[i] != '1')
                    i++;
            }
        }
        return ms;
    }
};