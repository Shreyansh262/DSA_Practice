class Solution {
public:
    string smallestPalindrome(string s) {
        int arr[26] = {0};
        for (char c : s) {
            arr[c - 'a']++;
        }
        char odd = '*';
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (arr[i] & 1) {
                odd = char('a' + i);
                arr[i]--;
            }
            if (arr[i] > 0)
                ans += string(arr[i] / 2, 'a' + i);
        }

        string rev = ans;
        reverse(rev.begin(), rev.end());
        if (odd != '*') {
            ans += odd;
        }
        ans = ans + rev;
        return ans;
    }
};