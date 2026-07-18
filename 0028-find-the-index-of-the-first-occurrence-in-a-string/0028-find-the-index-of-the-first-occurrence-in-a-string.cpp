class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
            return -1;
        int ans = -1;
        int j = 0, i;
        for (i = 0; i < haystack.size(); i++) {
            j = 0;
            while (haystack[i + j] == needle[j]) {
                j++;
                if (j == needle.size()) {
                    ans = i;
                    break;
                }

            }
            if(ans!=-1) break;

        }

        return ans;
    }
};